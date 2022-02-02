#pragma once

#include "structs.h"
#include "types.h"

typedef void(*AngleVectors_t)(const float *, float *, float *, float *);

typedef void(*Cbuf_AddText_t)(LocalClientNum_t localClientNum, const char *text);

typedef int(*G_DObjGetWorldTagPos_t)(const gentity_s *, scr_string_t, float *);
typedef void(*G_GetAngles_t)(LocalClientNum_t, short, float *);

typedef void(*Scr_AddEntity_t)(const gentity_s *);
typedef void(*Scr_AddInt_t)(int);
typedef void(*Scr_AddString_t)(const char *);
typedef void(*Scr_AddVector_t)(const float *);
typedef void(*Scr_MagicBullet_t)();
typedef void(*Scr_NotifyNum_t)(int entnum, unsigned int classnum, scr_string_t stringValue, unsigned int paramcount);

typedef const char *(*SL_ConvertToString_t)(scr_string_t stringValue);
typedef scr_string_t(*SL_GetString_t)(const char *, unsigned int);

//
extern AngleVectors_t AngleVectors;

extern Cbuf_AddText_t Cbuf_AddText;

extern G_DObjGetWorldTagPos_t G_DObjGetWorldTagPos;
extern G_GetAngles_t G_GetAngles;

extern Scr_AddEntity_t Scr_AddEntity;
extern Scr_AddInt_t Scr_AddInt;
extern Scr_AddString_t Scr_AddString;
extern Scr_AddVector_t Scr_AddVector;
extern Scr_MagicBullet_t Scr_MagicBullet;
extern Scr_NotifyNum_t Scr_NotifyNum;

extern SL_ConvertToString_t SL_ConvertToString;
extern SL_GetString_t SL_GetString;














typedef void (*AimTarget_GetTagPos_t)(uint64_t ent, unsigned short tagName, float *pos);
typedef bool (*AimTarget_IsTargetVisible_t)(LocalClientNum_t localClientNum, uint64_t targetEnt);

typedef bool(*CG_CanSeeFriendlyHeadTrace_t)(int localClientNum, uint64_t cent, const float *start, const float *end);
typedef bool (*CG_DObjGetWorldTagPos_t)(uint64_t ent, int obj, unsigned short tagName, float *pos);
typedef void (*CG_DrawRotatedPicPhysical_t)(const ScreenPlacement *screenPlacement, float x, float y, float width, float height, float angle, const float *color, uint64_t material, uint64_t image);
//typedef void(*CG_TracePoint_t)(trace_t *results, const float *start, const float *end, int passEntityNum, unsigned int contentMask, bool locational, bool staticModels, bool checkRopes, col_context_t *context, bool checkGlass);

typedef void (*CL_DrawText_t)(const unsigned int scrPlace, const char *text, int maxChars, int font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const float *color, int style);

typedef int (*DB_FindXAssetHeader_t)(int type, const char *name, bool errorIfMissing, int waitTime);

typedef void(*R_AddCmdDrawQuadPicW_t)(const float *verts, float w, const float *color, uint64_t material, uint64_t image);
typedef float (*R_TextWidth_t)(const char *text, int maxChars, uint64_t ttfFont, int textHeight, float letterSpacing);

typedef unsigned short (*SL_GetStringOfSize_t)(const char *str, unsigned int user, unsigned int len);

typedef void(*UI_DrawText_t)(const ScreenPlacement *screenPlacement, const char *text, int maxChars, uint64_t font, float x, float y, int horzAlign, int vertAlign, float scale, const float *color, int style, LocalClientNum_t localClientNum);
typedef void(*UI_FillRectPhysical_t)(float x, float y, float w, float h, const float *color);

typedef unsigned short(*sub_E9F770_t)(const char *str, unsigned int user, unsigned int u1);

//External
extern AimTarget_GetTagPos_t AimTarget_GetTagPos;
extern AimTarget_IsTargetVisible_t AimTarget_IsTargetVisible;

extern Cbuf_AddText_t Cbuf_AddText;

extern CG_CanSeeFriendlyHeadTrace_t CG_CanSeeFriendlyHeadTrace;
extern CG_DObjGetWorldTagPos_t CG_DObjGetWorldTagPos;
extern CG_DrawRotatedPicPhysical_t CG_DrawRotatedPicPhysical;
//extern CG_TracePoint_t CG_TracePoint;

extern CL_DrawText_t CL_DrawText;

extern DB_FindXAssetHeader_t DB_FindXAssetHeader;

extern R_AddCmdDrawQuadPicW_t R_AddCmdDrawQuadPicW;
extern R_TextWidth_t R_TextWidth;

extern SL_GetStringOfSize_t SL_GetStringOfSize;

extern UI_DrawText_t UI_DrawText;
extern UI_FillRectPhysical_t UI_FillRectPhysical;

extern sub_E9F770_t sub_E9F770;

//Custom
extern void AimTarget_GetTagPos_Custom(int entNum, const char *tagName, float *pos);
extern bool AimTarget_IsTargetVisible_Custom(int targetEntNum, const char *visBone);

extern bool Dvar_GetBool(const char *dvarName);
extern const char *Dvar_GetString(const char *dvarName);

extern int R_RegisterFont(const char *name, int imageTrack);
extern int R_TextHeight(uint64_t font);

void Scr_SetNumParam(int paramcount);

#include "global.h"
NAMESPACE(Functions)

//Functions
void Init();

END
