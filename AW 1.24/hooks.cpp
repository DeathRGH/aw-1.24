#include "hooks.h"

#include "cache.h"
#include "defines.h"
#include "functions.h"
#include "global.h"
#include "host.h"
#include "imports.h"
#include "menu.h"
#include "menuoptions.h"
#include "structs.h"
#include "utility.h"

NAMESPACE(Hooks)

CL_Disconnect_t CL_Disconnect_Stub;

void CL_Disconnect_Hook(LocalClientNum_t localClientNum, bool deactivateClient) {
	CreateThread((void *)PreventCrash, "preventCrash");

	CL_Disconnect_Stub(localClientNum, deactivateClient);
}

void R_EndFrame_Hook() {
	Menu::DrawMenu();

	//Font_s *newFont = R_RegisterFont("fonts/titleFont", 0);
	//DrawText(newFont->name, 500.0f, 500.0f, 1.0f, white10, newFont);

	//Material *newMaterial = Material_RegisterHandle("white", 0);
	//DrawText(newMaterial->name, 500.0f, 300.0f, 1.0f, white10, newFont);

	//DrawShader(500.0f, 650.0f, 600.0f, 100.0f, black08);
	//DrawTextWithGlow("Glowing Text", 500.0f, 750.0f, 1.0f, white10, cyan10);

	//DrawCenterTextWithBackground("ooo O ooo", 1920 / 2, 1080 / 2, 0.4f, white10, black05);
	//DrawShader(1920 / 2 - 2, 1080 / 2 - 2, 4.0f, 4.0f, cyan10);


	//reversed below
	R_GetCommandBuffer((GfxRenderCommand)0, 4);
	*(uint64_t *)((*(uint64_t *)(*(uint64_t *)0x000000000CA50200 + 0x546A40)) + 0x18) = 0;
	*(uint64_t *)((*(uint64_t *)(*(uint64_t *)0x000000000CA50200 + 0x546A40)) + 0x10) = 0;
	*(uint64_t *)((*(uint64_t *)(*(uint64_t *)0x000000000CA50200 + 0x546A40)) + 0x08) = 0;
	*(int *)(0x000000000C9C2400 + 0xD08) = 0;
	*(int *)0x000000000E35B2A4 = (*(int *)0x000000000E35B2A4 & 1) ^ 1;
}

void Scr_Notify_Hook(gentity_s *ent, scr_string_t stringValue, unsigned int paramcount) {
	if (!strcmp(SL_ConvertToString(stringValue), "weapon_fired")) {
		//uartprintf("weapon_fired\n");
		if (Menu::Options.host_magicBullet.state)
			Host::FireMagicBullet(*(short *)ent, MagicBulletProjectileForIndex(Menu::Options.host_magicBulletProjectileIndex.current));

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

END
