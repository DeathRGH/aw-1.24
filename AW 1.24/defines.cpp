#include "defines.h"

#include "functions.h"
#include "imports.h"
#include "library_functions.h"
#include "structs.h"
#include "utility.h"

const char *FontForIndex(int index) {
	if (index == 0)
		return "fonts/dev.ttf";
	if (index == 1)
		return "fonts/default.ttf";
	if (index == 2)
		return "fonts/consoleFont";
	if (index == 3)
		return "fonts/bigFont";
	if (index == 4)
		return "fonts/smallFont";
	if (index == 5)
		return "fonts/boldFont";
	if (index == 6)
		return "fonts/normalFont";
	if (index == 7)
		return "fonts/extraBigFont";
	if (index == 8)
		return "fonts/objectiveFont";
	else
		return "fonts/normalFont";
}

const char *DisplayFontForIndex(int index) {
	if (index == 0)
		return "Small Dev Font";
	if (index == 1)
		return "Big Dev Font";
	if (index == 2)
		return "Console Font";
	if (index == 3)
		return "Big Font";
	if (index == 4)
		return "Small Font";
	if (index == 5)
		return "Bold Font";
	if (index == 6)
		return "Normal Font";
	if (index == 7)
		return "Extra Big Font";
	if (index == 8)
		return "Objective Font";
	else
		return "Normal Font";
}

const char *AimbotBoneForIndex(int index) {
	if (index == 0)
		return "j_helmet";
	if (index == 1)
		return "j_head";
	if (index == 2)
		return "j_neck";
	if (index == 3)
		return "j_spine4";
	if (index == 4)
		return "j_spineupper";
	if (index == 5)
		return "j_spinelower";
	if (index == 6)
		return "j_mainroot";
	if (index == 7)
		return "j_shoulder_le";
	if (index == 8)
		return "j_shoulder_ri";
	if (index == 9)
		return "j_elbow_le";
	if (index == 10)
		return "j_elbow_ri";
	if (index == 11)
		return "j_wrist_le";
	if (index == 12)
		return "j_wrist_ri";
	if (index == 13)
		return "j_hip_le";
	if (index == 14)
		return "j_hip_ri";
	if (index == 15)
		return "j_knee_le";
	if (index == 16)
		return "j_knee_ri";
	if (index == 17)
		return "j_ankle_le";
	if (index == 18)
		return "j_ankle_ri";
	if (index == 19)
		return "j_ball_le";
	if (index == 20)
		return "j_ball_ri";
	else
		return "j_head";
}

const char *CustomCrosshairTypeForIndex(int index) {
	if (index == CROSSHAIRTYPE_CROSS)
		return "Cross";
	if (index == CROSSHAIRTYPE_PLUS)
		return "Plus";
	if (index == CROSSHAIRTYPE_FILLBOX)
		return "Fill Box";
	if (index == CROSSHAIRTYPE_BOX)
		return "Box";
	if (index == CROSSHAIRTYPE_CIRCLE)
		return "Circle";
	if (index == CROSSHAIRTYPE_SPIRAL)
		return "Spiral";
	if (index == CROSSHAIRTYPE_SPINNING)
		return "Spinning";
	else
		return "Cross";
}

const char *ESPTargetTeamForIndex(int index) {
	if (index == ESP_TEAM_ENEMY)
		return "Enemy";
	if (index == ESP_TEAM_FRIENDLY)
		return "Friendly";
	if (index == ESP_TEAM_BOTH)
		return "Enemy & Friendly";
	else
		return "Enemy & Friendly";
}

const char *ESPTypeForIndex(int index) {
	if (index == 0)
		return "Off";
	if (index == 1)
		return "Box";
	if (index == 2)
		return "Fill Box";
	if (index == 3)
		return "Corners";
	if (index == 4)
		return "3D Box";
	if (index == 5)
		return "Pyramid";
	else
		return "3D Box";
}

const char *GetRawWeaponNameForIndex(int id) {
	return (char *)(*(long long *)(*(long long *)(bg_weaponCompleteDefs + ((id * 8) & 0x3FC)) + 0x10));
}

const char *GetWeaponNameForIndex(int id) {
	return "";//UI_SafeTranslateString(GetRawWeaponNameForIndex(id));
}

uint64_t GetTTFForFont(uint64_t font) {
	return *(uint64_t *)(font + 0x08);
}

bool WorldToScreen(float *worldLocation, float *screen) {
	float local[3];
	float transform[3];

	local[0] = worldLocation[0] - cg.refdef.vieworg[0];
	local[1] = worldLocation[1] - cg.refdef.vieworg[1];
	local[2] = worldLocation[2] - cg.refdef.vieworg[2];

	transform[0] = DotProduct(local, cg.refdef.viewaxis[1]);
	transform[1] = DotProduct(local, cg.refdef.viewaxis[2]);
	transform[2] = DotProduct(local, cg.refdef.viewaxis[0]);

	if (transform[2] < 0.01f)
		return false;

	screen[0] = (cg.refdef.width / 2) * (1.0f - (transform[0] / cg.refdef.tanHalfFovX / transform[2]));
	screen[1] = (cg.refdef.height / 2) * (1.0f - (transform[1] / cg.refdef.tanHalfFovY / transform[2]));

	return (transform[2] > 0);
}

void OffHost_EndGame() {
	char temp[100];
	snprintf(temp, sizeof(temp), "cmd mrp %i 13 8 0", clientActive.serverId);
	Cbuf_AddText((LocalClientNum_t)0, temp);
}

void SendConsoleCommand() {
	OpenKeyboardDialog(100, "Console Command");
	Cbuf_AddText((LocalClientNum_t)0, sceImeKeyboardRetVal);
}

bool gameEnded = false;
void PreventCrash() {
	gameEnded = true;
	Sleep(5000);
	gameEnded = false;
}

bool InGame() {
	return true;//!gameEnded && *(char *)vHandler->addresses.addr_inGame == 0 && *(uint64 *)vHandler->structDefs.addr_cg != 0 && *(uint64 *)vHandler->structDefs.addr_cgs != 0 && *(uint64 *)vHandler->structDefs.addr_centity != 0 && *(uint64 *)vHandler->structDefs.addr_clientActive != 0;
}

const char *GetRawGametype() {
	return cgs.gametype;
}

const char *GetRawMapname() {
	return cgs.mapname;
}

void DrawText(const char *text, float x, float y, uint64_t font, float fontSize, float *color) {
	UI_DrawText(ScrPlace, text, 0x7FFFFFFF, font, x, y, 0, 0, fontSize, color, 0, LocalClientNum_t::LOCAL_CLIENT_0);
}

void DrawText(const char *text, float x, float y, const char *font, float fontSize, float *color) {
	UI_DrawText(ScrPlace, text, 0x7FFFFFFF, MENU_FONT, x, y, 0, 0, fontSize, color, 0, LocalClientNum_t::LOCAL_CLIENT_0);
}

void DrawText(const char *text, float x, float y, float fontSize, float *color) {
	UI_DrawText(ScrPlace, text, 0x7FFFFFFF, MENU_FONT, x, y, 0, 0, fontSize, color, 0, LocalClientNum_t::LOCAL_CLIENT_0);
}

void DrawShader(float x, float y, float width, float height, float *color, int shader) {
	//R_AddCmdDrawStretchPic(x, y, width, height, 0, 0, 1, 1, color, shader);
}

void DrawShader(float x, float y, float width, float height, float *color, const char *shader) {
	//R_AddCmdDrawStretchPic(x, y, width, height, 0, 0, 1, 1, color, Material_RegisterHandle(shader, 0));
}

void DrawShader(float x, float y, float width, float height, float *color) {
	UI_FillRectPhysical(x, y, width, height, color);
	//R_AddCmdDrawStretchPic(x, y, width, height, 0, 0, 1, 1, color, Material_RegisterHandle("white", 0));
}

void DrawCenterTextWithBackground(const char *text, float x, float y, float *color, float fontSize, float *backgroundColor) {
	float textWidth = R_TextWidth(text, 0x7FFFFFFF, GetTTFForFont(FONT_DEFAULT), R_TextHeight(FONT_DEFAULT), 1.5f) * fontSize;
	float textHeight = R_TextHeight(MENU_FONT) * fontSize;

	UI_FillRectPhysical(x - 4 - textWidth / 2, y - (textHeight * 0.2f) - textHeight / 2, textWidth + 8, textHeight + (textHeight * 0.2f), backgroundColor);
	UI_DrawText(ScrPlace, text, 0x7FFFFFFF, MENU_FONT, x - textWidth / 2, y + textHeight / 2, 0, 0, fontSize, color, 0, LocalClientNum_t::LOCAL_CLIENT_0);
	//R_AddCmdDrawStretchPic(x - textWidth / 2, y - textHeight / 2, textWidth, textHeight, 0, 0, 1, 1, backgroundColor, Material_RegisterHandle("white", 0));
	//R_AddCmdDrawText(text, 0x7FFFFFFF, fontAsInt, x - textWidth / 2, y + textHeight / 2, fontSize, fontSize, 0, color, 0);
}

void DrawCenterTextWithBackgroundWithBorder(const char *text, float x, float y, float *color, float fontSize, float *backgroundColor, int borderSize, float *borderColor) {
	float textWidth = R_TextWidth(text, 0x7FFFFFFF, GetTTFForFont(FONT_DEFAULT), R_TextHeight(FONT_DEFAULT), 1.5f) * fontSize;
	float textHeight = R_TextHeight(MENU_FONT) * fontSize;

	UI_FillRectPhysical(x - 4 - textWidth / 2, y - (textHeight * 0.2f) - borderSize - textHeight / 2, textWidth + 8, textHeight + (textHeight * 0.2f), backgroundColor);
	UI_FillRectPhysical(x - 4 - borderSize - textWidth / 2, y - (textHeight * 0.2f) - borderSize * 2 - textHeight / 2, borderSize, textHeight + (textHeight * 0.2f) + 2 * borderSize, borderColor); //left
	UI_FillRectPhysical(x + 4 + textWidth / 2, y - (textHeight * 0.2f) - borderSize * 2 - textHeight / 2, borderSize, textHeight + (textHeight * 0.2f) + 2 * borderSize, borderColor); //right
	UI_FillRectPhysical(x - 4 - textWidth / 2, y - (textHeight * 0.2f) - borderSize * 2 - textHeight / 2, textWidth + 8, borderSize, borderColor); //top
	UI_FillRectPhysical(x - 4 - textWidth / 2, y - borderSize + textHeight / 2, textWidth + 8, borderSize, borderColor); //bottom
	UI_DrawText(ScrPlace, text, 0x7FFFFFFF, MENU_FONT, x - textWidth / 2, y - borderSize + textHeight / 2, 0, 0, fontSize, color, 0, LocalClientNum_t::LOCAL_CLIENT_0);
}

void DrawLine(float x1, float y1, float x2, float y2, float width, float *color) {
	float x, y, angle, L1, L2, H1;
	H1 = y2 - y1;
	L1 = x2 - x1;
	L2 = sqrt(L1 * L1 + H1 * H1);
	x = x1 + ((L1 - L2) / 2);
	y = y1 + (H1 / 2);
	angle = (float)atan(H1 / L1) * (180.0f / MATH_PI);
	//CG_DrawRotatedPicPhysical(ScrPlace, x, y, L2, width, angle, color, *(uint64_t *)vHandler->defs.addr_Material_white, 0);
}

float hexDumpCyan[4] = { 0.0f, 0.48f, 0.8f, 1.0f };

void DrawHexDump(float x, float y, uint64_t address, int length, float fontSize) {
	int addressWidth = R_TextWidth("FFFFFFFFFFFFFFFF", 0x7FFFFFFF, GetTTFForFont(FONT_DEFAULT), R_TextHeight(FONT_DEFAULT), 1.5f) * fontSize;
	
	DrawShader(x, y, 660.0f, 40.0f + (length / 16) * 20.0f, black10);

	for (int i = 0; i < 16; i++) {
		char temp[100];
		snprintf(temp, sizeof(temp), "%02X", i);
		DrawText(temp, x + addressWidth + 10.0f + (i % 16) * 30.0f, y + 10.0f + R_TextHeight(FONT_DEFAULT) * fontSize + (i / 16) * 20.0f, 0.4f, hexDumpCyan);
	}

	for (int i = 0; i < length / 16; i++) {
		char temp[100];
		snprintf(temp, sizeof(temp), "%016X", /*address + */i * 16);
		DrawText(temp, x + 10.0f, y + 15.0f + R_TextHeight(FONT_DEFAULT) * fontSize * 2 + i * 20.0f, 0.4f, hexDumpCyan);
	}

	for (int i = 0; i < length; i++) {
		char temp[100];
		snprintf(temp, sizeof(temp), "%02X", *(unsigned char *)(address + i));
		DrawText(temp, x + addressWidth + 10.0f + (i % 16) * 30.0f, y + 15.0f + R_TextHeight(FONT_DEFAULT) * fontSize * 2 + (i / 16) * 20.0f, 0.4f, white10);
	}
}
