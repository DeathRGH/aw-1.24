#pragma once

#include "global.h"

#define MAX_CLIENTS 18
#define MAX_ENTITYS 2048
#define NUM_FONTS 8
#define NUM_BONES 20

#define ScrPlace (ScreenPlacement *)0x00//vHandler->defs.addr_CustomScreenPlacement
#define bg_weaponCompleteDefs 0x3DF7400 //


//00000000026EE8A0 weapondef ( & 0x3FF)

//0x00000000064293D0 //gentity //0x2E0

//0x000000000659C180 //gclient //0x5780
//0x5370 - mflag


//dvars
#define dvar_s_current 0x10
#define dvar_s_default 0x30
#define dvar_s_min 0x40
#define dvar_s_max 0x44
//dvar types (dvar_s + 0x0C) (1 byte)
//0 = bool
//1 = float
//1 = int
//6 = string

#define cg_fov 0x3E2BF10 //

#define FONT_DEFAULT 0x00 //vHandler->defs.addr_Font_Default

#define MENU_FONT FONT_DEFAULT

enum XAssetType_t {
	ASSET_TYPE_XMODEL = 0x04,
	ASSET_TYPE_MATERIAL = 0x06,
	ASSET_TYPE_IMAGE = 0x09,
	ASSET_TYPE_CHARACTER = 0x2D,
	ASSET_TYPE_XMODELALIAS = 0x2E,
	ASSET_TYPE_TRACER = 0x3A,
	ASSET_TYPE_TTF = 0x50
};

enum CrosshairType_t {
	CROSSHAIRTYPE_CROSS,
	CROSSHAIRTYPE_PLUS,
	CROSSHAIRTYPE_FILLBOX,
	CROSSHAIRTYPE_BOX,
	CROSSHAIRTYPE_CIRCLE,
	CROSSHAIRTYPE_SPIRAL,
	CROSSHAIRTYPE_SPINNING
};

enum EspTeam_t {
	ESP_TEAM_ENEMY,
	ESP_TEAM_FRIENDLY,
	ESP_TEAM_BOTH
};

const char *FontForIndex(int index);
const char *DisplayFontForIndex(int index);
const char *AimbotBoneForIndex(int index);
const char *CustomCrosshairTypeForIndex(int index);
const char *ESPTargetTeamForIndex(int index);
const char *ESPTypeForIndex(int index);

const char *GetRawWeaponNameForIndex(int id);
const char *GetWeaponNameForIndex(int id);

uint64_t GetTTFForFont(uint64_t font);

bool WorldToScreen(float *worldLocation, float *screen);

void OffHost_EndGame();
void SendConsoleCommand();

extern bool gameEnded;
void PreventCrash();
bool InGame();
const char *GetRawGametype();
const char *GetRawMapname();

void DrawText(const char *text, float x, float y, uint64_t font, float fontSize, float *color);
void DrawText(const char *text, float x, float y, const char *font, float fontSize, float *color);
void DrawText(const char *text, float x, float y, float fontSize, float *color);
void DrawShader(float x, float y, float width, float height, float *color, int shader);
void DrawShader(float x, float y, float width, float height, float *color, const char *shader);
void DrawShader(float x, float y, float width, float height, float *color);
void DrawCenterTextWithBackground(const char *text, float x, float y, float *color = white10, float fontSize = 0.5f, float *backgroundColor = black08);
void DrawCenterTextWithBackgroundWithBorder(const char *text, float x, float y, float *color = white10, float fontSize = 0.5f, float *backgroundColor = black08, int borderSize = 2, float *borderColor = white10);
void DrawLine(float x1, float y1, float x2, float y2, float width, float *color);
void DrawHexDump(float x, float y, uint64_t address, int length, float fontSize);
