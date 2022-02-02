#include "functions.h"

AngleVectors_t AngleVectors;

Cbuf_AddText_t Cbuf_AddText;

G_DObjGetWorldTagPos_t G_DObjGetWorldTagPos;
G_GetAngles_t G_GetAngles;

R_GetCommandBuffer_t R_GetCommandBuffer;

Scr_AddEntity_t Scr_AddEntity;
Scr_AddInt_t Scr_AddInt;
Scr_AddString_t Scr_AddString;
Scr_AddVector_t Scr_AddVector;
Scr_MagicBullet_t Scr_MagicBullet;
Scr_NotifyNum_t Scr_NotifyNum;

SL_ConvertToString_t SL_ConvertToString;
SL_GetString_t SL_GetString;











AimTarget_GetTagPos_t AimTarget_GetTagPos;
AimTarget_IsTargetVisible_t AimTarget_IsTargetVisible;

CG_CanSeeFriendlyHeadTrace_t CG_CanSeeFriendlyHeadTrace;
CG_DObjGetWorldTagPos_t CG_DObjGetWorldTagPos;
CG_DrawRotatedPicPhysical_t CG_DrawRotatedPicPhysical;
//CG_TracePoint_t CG_TracePoint;

CL_DrawText_t CL_DrawText;

DB_FindXAssetHeader_t DB_FindXAssetHeader;

R_AddCmdDrawQuadPicW_t R_AddCmdDrawQuadPicW;
R_TextWidth_t R_TextWidth;

SL_GetStringOfSize_t SL_GetStringOfSize;

UI_DrawText_t UI_DrawText;
UI_FillRectPhysical_t UI_FillRectPhysical;

sub_E9F770_t sub_E9F770;

//Custom
void AimTarget_GetTagPos_Custom(int entNum, const char *tagName, float *pos) {
	int dobj = 0;//Com_GetClientDObj(centity[entNum].nextState.number, 0);

	if (!dobj)
		return;

	//CG_DObjGetWorldTagPos(centity[entNum].__address, dobj, SL_GetString(tagName), pos);
}

bool AimTarget_IsTargetVisible_Custom(int targetEntNum, const char *visBone) {
	float tagPos[3];
	//AimTarget_GetTagPos_Custom(targetEntNum, visBone, tagPos);

	//float mins[3] = { 0.0f, 0.0f, 0.0f };
	//float maxs[3] = { 99999.0f, 99999.0f, 99999.0f };

	//trace_t trace;
	//col_context_t cont;
	//cont.mask = 0x280B001;
	//cont.passEntityNum0 = 0x3FF;
	//cont.passEntityNum1 = 0x3FF;
	//cont.param1 = 0xFFFFFFFF;

	//cont.mask = 0x280E813;
	//CM_Trace(&trace, cg.refdef.vieworg, tagPos, mins, maxs, 0, 0x280E813, &cont);

	//CG_TracePoint(&trace, cg.refdef.vieworg, tagPos, 0x3FF, 0x280B001, true, true, false, &cont, false);

	return AimTarget_IsTargetVisible(LocalClientNum_t::LOCAL_CLIENT_0, centity[targetEntNum].__address);
	//return true;//CG_CanSeeFriendlyHeadTrace(0, cent, cg.refdef.vieworg, tagPos); //AimTarget_IsTargetVisible(0, cent);
	//return trace.fraction >= 1.0f;
}

bool Dvar_GetBool(const char *dvarName) {
	int dvar_s = 0; //Dvar_FindVar(dvarName);
	if (dvar_s)
		return *(bool **)(dvar_s + 0x10);
}

const char *Dvar_GetString(const char *dvarName) {
	int dvar_s = 0; //Dvar_FindVar(dvarName);
	if (dvar_s)
		return *(const char **)(dvar_s + 0x10);
}

int R_RegisterFont(const char *name, int imageTrack) {
	return MENU_FONT;
}

int R_TextHeight(uint64_t font) {
	return *(int *)(font + 0x10) * 1.5f;
}

void Scr_SetNumParam(int paramcount) {
	*(int*)(0x000000000A6C6098 + 0x2C) = paramcount;
}