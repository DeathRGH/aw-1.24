#include <stdint.h>
#include <stdarg.h>

#include "defines.h"
#include "detour.h"
#include "functions.h"
#include "global.h"
#include "hooks.h"
#include "imports.h"
#include "library_functions.h"
#include "menu.h"
#include "menuoptions.h"
#include "types.h"
#include "utility.h"

static int step;
void RgbThread() {
	uartprintf("RgbThread() -> THREAD STARTED!\n");
	while (ShouldRun()) {

		float inc = 0.005f;//Menu::options.rgbFadingSpeed.current;

		if (step == 0)
			(rgbColor10[2] < (1.0f - inc * 2.0f)) ? rgbColor10[2] += inc : step = 1;
		if (step == 1)
			(rgbColor10[0] > (inc * 2.0f)) ? rgbColor10[0] -= inc : step = 2;
		if (step == 2)
			(rgbColor10[1] < (1.0f - inc * 2.0f)) ? rgbColor10[1] += inc : step = 3;
		if (step == 3)
			(rgbColor10[2] > (inc * 2.0f)) ? rgbColor10[2] -= inc : step = 4;
		if (step == 4)
			(rgbColor10[0] < (1.0f - inc * 2.0f)) ? rgbColor10[0] += inc : step = 5;
		if (step == 5)
			(rgbColor10[1] > (inc * 2.0f)) ? rgbColor10[1] -= inc : step = 0;

		UpdateRGB();



		Sleep(10);
	}

	uartprintf("RgbThread() -> THREAD ENDED!\n");
}

typedef void(*PlayerCmd_AllowBoostJump_t)(scr_entref_t);
PlayerCmd_AllowBoostJump_t PlayerCmd_AllowBoostJump = (PlayerCmd_AllowBoostJump_t)0x000000000070F100;

typedef void(*PlayerCmd_AllowDodge_t)(scr_entref_t);
PlayerCmd_AllowDodge_t PlayerCmd_AllowDodge = (PlayerCmd_AllowDodge_t)0x000000000070F180;

typedef void(*PlayerCmd_AllowPowerSlide_t)(scr_entref_t);
PlayerCmd_AllowPowerSlide_t PlayerCmd_AllowPowerSlide = (PlayerCmd_AllowPowerSlide_t)0x000000000070F200;

typedef void(*PlayerCmd_AllowHighJumpDrop_t)(scr_entref_t);
PlayerCmd_AllowHighJumpDrop_t PlayerCmd_AllowHighJumpDrop = (PlayerCmd_AllowHighJumpDrop_t)0x000000000070F280;

typedef void(*PlayerCmd_AllowLadder_t)(scr_entref_t);
PlayerCmd_AllowLadder_t PlayerCmd_AllowLadder = (PlayerCmd_AllowLadder_t)0x000000000070F300;

typedef void(*PlayerCmd_AllowMantle_t)(scr_entref_t);
PlayerCmd_AllowMantle_t PlayerCmd_AllowMantle = (PlayerCmd_AllowMantle_t)0x000000000070F3B0;

typedef void(*PlayerCmd_AllowSprint_t)(scr_entref_t);
PlayerCmd_AllowSprint_t PlayerCmd_AllowSprint = (PlayerCmd_AllowSprint_t)0x000000000070F460;

typedef void(*PlayerCmd_ForceMantle_t)(scr_entref_t);
PlayerCmd_ForceMantle_t PlayerCmd_ForceMantle = (PlayerCmd_ForceMantle_t)0x0000000000710740;

typedef void(*PlayerCmd_setOrigin_t)(scr_entref_t);
PlayerCmd_setOrigin_t PlayerCmd_setOrigin = (PlayerCmd_setOrigin_t)0x000000000070C800;

typedef void(*PlayerCmd_SetClientDvar_t)(scr_entref_t);
PlayerCmd_SetClientDvar_t PlayerCmd_SetClientDvar = (PlayerCmd_SetClientDvar_t)0x000000000070EA60;

typedef void(*SV_GameSendServerCommand_t)(signed char, int, char const*);
SV_GameSendServerCommand_t SV_GameSendServerCommand = (SV_GameSendServerCommand_t)0x000000000089CD80;

void FireMagicBullet(short entNum, const char *projectile) {
	float playerAngles[3];
	playerAngles[0] = *(float *)((entNum * 0x5780) + 0x000000000659C180 + 0x1B4);
	playerAngles[1] = *(float *)((entNum * 0x5780) + 0x000000000659C180 + 0x1B4 + 4);
	playerAngles[2] = *(float *)((entNum * 0x5780) + 0x000000000659C180 + 0x1B4 + 8);

	float forward[3];
	AngleVectors(playerAngles, forward, 0, 0);
	forward[0] *= 999999999.0f;
	forward[1] *= 999999999.0f;
	forward[2] *= 999999999.0f;

	float startPos[3];
	G_DObjGetWorldTagPos((gentity_s *)0x00000000064293D0 + (entNum * 0x2E0), SL_GetString("tag_weapon_right", 0), startPos);

	Scr_AddVector(forward);
	Scr_AddVector(startPos);
	Scr_AddString(projectile);
	Scr_SetNumParam(3);

	Scr_MagicBullet();
}

void Scr_Notify_Hook(gentity_s *ent, scr_string_t stringValue, unsigned int paramcount) {
	if (!strcmp(SL_ConvertToString(stringValue), "weapon_fired")) {
		uartprintf("weapon_fired\n");
		FireMagicBullet(*(short *)ent, "iw5_juggernautrockets_mp");

		//float newPos[3] = { 0.0f, 0.0f, 0.0f };
		//Scr_AddVector(newPos);
		//Scr_SetNumParam(1);
		//PlayerCmd_setOrigin(**(short *)ent);

		//Scr_AddInt(1);
		//Scr_AddString("cg_fov");
		//Scr_AddString("120");
		//Scr_SetNumParam(3);
		//PlayerCmd_SetClientDvar(*(short *)ent);

		//Scr_AddInt(0);
		//Scr_SetNumParam(1);
		//PlayerCmd_ForceMantle(*(short *)ent);
	}

	Scr_NotifyNum(*(short *)ent, 0, stringValue, paramcount);
}

void DetectGame() {
	if (!strcmp((char *)0x0000000000BFB355, "multiplayer")) {
		executionAddress = 0x0000000000D43FF0;
		NewRunID();

		ScePthread thread1;
		scePthreadCreate(&thread1, NULL, (void *)RgbThread, NULL, "rgb_thread");
		ScePthread thread2;
		scePthreadCreate(&thread2, NULL, (void *)Menu::MonitorButtons, NULL, "monitorButtons_thread");
		ScePthread thread3;
		scePthreadCreate(&thread3, NULL, (void *)Menu::LoopSettings, NULL, "loopSettings_thread");

		char userName[20];
		sceUserServiceGetUserName(userId, userName, 20);

		char welcomeMessage[100];
		snprintf(welcomeMessage, sizeof(welcomeMessage), "Welcome %s!\n[AW 1.24] - Loaded\n\nHold  and press .", userName);
		sceSysUtilSendSystemNotificationWithText(222, welcomeMessage);

		Functions::Init();
		Menu::Init();

		//memcpy((void *)vHandler->patches.addr_LobbyDebug, "\xE9\xA9\x00\x00\x00\x90", 6); //enable LobbyDebug_Draw

		//restore CL_Disconnect
		//memcpy((void *)0xB6F7F0, "\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x48\x83\xEC\x68", 17);
		//Hooks::CL_Disconnect_s = (Hooks::CL_Disconnect_t)DetourFunction(0xB6F7F0, (void *)Hooks::CL_Disconnect_Hook, 17);

		WriteJump(0x0000000000766450, (uint64_t)Scr_Notify_Hook);
	}
	else {
		sceSysUtilSendSystemNotificationWithText(222, "Welcome to AW 1.24");
		OpenMessageDialog("AW 1.24\n\nWrong game or update version detected!\n\nSupported:\nCUSA00803 (Update 1.24)\nCUSA00851 (Update 1.24)");
		return;
	}
}

extern "C" void _main(void) {
	initImports();
	Sleep(100);

	SceUserServiceLoginUserIdList userIdList;
	sceUserServiceGetLoginUserIdList(&userIdList);

	for (int i = 0; i < 4; i++) {
		if (userIdList.userId[i] != -1) {
			userId = userIdList.userId[i];
			break;
		}
	}

	userPadHandle = scePadGetHandle(userId, 0, 0);

	DetectGame();
}
