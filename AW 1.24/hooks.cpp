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

LUI_CoD_Render_t LUI_CoD_Render_Stub;
LUIElement_Render_t LUIElement_Render_Stub;

void CL_Disconnect_Hook(LocalClientNum_t localClientNum, bool deactivateClient) {
	CreateThread((void *)PreventCrash, "preventCrash");

	CL_Disconnect_Stub(localClientNum, deactivateClient);
}

typedef void(*LUI_Interface_DrawRectangle_t)(LUIElement *, float x, float y, float width, float height, float, float, float, float, float, float, float, Material *, float *, LUI_QuadRenderMode, bool, lua_State *);
LUI_Interface_DrawRectangle_t LUI_Interface_DrawRectangle = (LUI_Interface_DrawRectangle_t)0x00000000004F2650;

typedef void(*LUI_Interface_DrawTextWithCursor_t)(LUIElement *, float, float, float, float, float, float, const char *, Font_s *, float, float, int, char, lua_State *);
LUI_Interface_DrawTextWithCursor_t LUI_Interface_DrawTextWithCursor = (LUI_Interface_DrawTextWithCursor_t)0x00000000004F3560;

typedef void(*LUI_Interface_DrawBoundingBox_t)(LUIElement *, lua_State *);
LUI_Interface_DrawBoundingBox_t LUI_Interface_DrawBoundingBox = (LUI_Interface_DrawBoundingBox_t)0x00000000004F2E90;

void LUI_CoD_Render_Hook(LocalClientNum_t rdi, int rsi) {
	LUI_CoD_Render_Stub(rdi, rsi);

	LUIElement *rootElem = LUI_GetRootElement("UIRootFull", lua_state);
	LUI_Interface_DrawLine(rootElem, 0.0f, 0.0f, 500.0f, 500.0f, 0, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f);
	LUI_Interface_DrawLine(rootElem, 500.0f, 0.0f, 0.0f, 500.0f, 0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);

	//LUI_Interface_DrawTextWithCursor(rootElem, 100.0f, 100.0f, 10.0f, 10.0f, 10.0f, 10.0f, "LUI Test Text", R_RegisterFont("fonts/bodyFont", 0), 10.0f, 10.0f, 20, 0, lua_state);
	//LUI_Interface_DrawRectangle(rootElem, 100.0f, 200.0f, 300.0f, 500.0f, 100.0f, 200.0f, 100.0f, 200.0f, 300.0f, 400.0f, 600.0f, Material_RegisterHandle("white", 0), red10, (LUI_QuadRenderMode)0, true, lua_state);
}

void LUI_Interface_DebugPrint_Hook(const char *fmt, ...) {
	char buffer[2048];
	va_list args;
	va_start(args, fmt);
	vsprintf(buffer, fmt, args);
	va_end(args);

	char buffer2[2048];
	snprintf(buffer2, sizeof(buffer2), "[AW 1.24] <LUI> %s", buffer);
	sceKernelDebugOutText(DGB_CHANNEL_TTYL, buffer2);
}

void LUIElement_Render_Hook(LocalClientNum_t rdi, LUIElement *rsi, LUIElement *rdx, RootUserData *rcx, int r8d, lua_State *r9, float xmm0) {
	LUIElement_Render_Stub(rdi, rsi, rdx, rcx, r8d, r9, xmm0);
	//uartprintf("0x%llX, 0x%llX, 0x%llX, 0x%llX\n", rsi, rdx, rcx, r9);

	//LUIElement *rootElem = LUI_GetRootElement("UIRootFull", r9);
	//LUI_Interface_DrawLine(rootElem, 0.0f, 0.0f, 500.0f, 500.0f, 0, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f);
	//LUI_Interface_DrawLine(rootElem, 500.0f, 0.0f, 0.0f, 500.0f, 0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	
	//LUI_Interface_DrawBoundingBox(rootElem, r9);

	//LUI_Interface_DrawTextWithCursor(rootElem, 100.0f, 100.0f, 10.0f, 10.0f, 10.0f, 10.0f, "LUI Test Text", R_RegisterFont("fonts/bodyFont", 0), 10.0f, 10.0f, 20, 0, r9);

	//((void(*)(LUIElement *, float x, float y, float, float, float, float, float, float, float, float, float, Material *, float *, LUI_QuadRenderMode, bool, lua_State *))0x00000000004F2CA0)(rsi, 100.0f, 100.0f, 300.0f, 200.0f, 0, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, );
	//LUI_Interface_DrawRectangle(rootElem, 100.0f, 200.0f, 300.0f, 200.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, Material_RegisterHandle("white", 0), red10, (LUI_QuadRenderMode)0, true, r9);
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
