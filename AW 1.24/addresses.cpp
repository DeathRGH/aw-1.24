#include "functions.h"

NAMESPACE(Functions)

void Init() {
	AngleVectors = (AngleVectors_t)0x0000000000921200;

	Cbuf_AddText = (Cbuf_AddText_t)0x00000000007F6020;

	G_DObjGetWorldTagPos = (G_DObjGetWorldTagPos_t)0x000000000076B250;
	G_GetAngles = (G_GetAngles_t)0x000000000076C310;

	Material_RegisterHandle = (Material_RegisterHandle_t)0x0000000000A058D0;

	PlayerCmd_AllowBoostJump = (PlayerCmd_AllowBoostJump_t)0x000000000070F100;
	PlayerCmd_AllowDodge = (PlayerCmd_AllowDodge_t)0x000000000070F180;
	PlayerCmd_AllowHighJumpDrop = (PlayerCmd_AllowHighJumpDrop_t)0x000000000070F280;
	PlayerCmd_AllowLadder = (PlayerCmd_AllowLadder_t)0x000000000070F300;
	PlayerCmd_AllowMantle = (PlayerCmd_AllowMantle_t)0x000000000070F3B0;
	PlayerCmd_AllowPowerSlide = (PlayerCmd_AllowPowerSlide_t)0x000000000070F200;
	PlayerCmd_AllowSprint = (PlayerCmd_AllowSprint_t)0x000000000070F460;
	PlayerCmd_ForceMantle = (PlayerCmd_ForceMantle_t)0x0000000000710740;
	PlayerCmd_SetClientDvar = (PlayerCmd_SetClientDvar_t)0x000000000070EA60;
	PlayerCmd_setOrigin = (PlayerCmd_setOrigin_t)0x000000000070C800;

	R_AddCmdDrawStretchPic = (R_AddCmdDrawStretchPic_t)0x0000000000A15D10;
	R_AddCmdDrawText = (R_AddCmdDrawText_t)0x0000000000A16340;
	R_AddCmdDrawTextWithEffects = (R_AddCmdDrawTextWithEffects_t)0x0000000000A16480;
	R_GetCommandBuffer = (R_GetCommandBuffer_t)0x0000000000A15660;
	R_RegisterFont = (R_RegisterFont_t)0x00000000009FB230;
	R_TextHeight = (R_TextHeight_t)0x00000000009FB480;
	R_TextWidth = (R_TextWidth_t)0x00000000009FB2E0;

	Scr_AddEntity = (Scr_AddEntity_t)0x00000000007662C0;
	Scr_AddInt = (Scr_AddInt_t)0x00000000008547E0;
	Scr_AddString = (Scr_AddString_t)0x0000000000854AD0;
	Scr_AddVector = (Scr_AddVector_t)0x0000000000854CE0;
	Scr_MagicBullet = (Scr_MagicBullet_t)0x000000000073BBB0;
	Scr_NotifyNum = (Scr_NotifyNum_t)0x0000000000852AE0;
	
	SL_ConvertToString = (SL_ConvertToString_t)0x000000000084AF50;
	SL_GetString = (SL_GetString_t)0x000000000084B820;

	SV_GameSendServerCommand = (SV_GameSendServerCommand_t)0x000000000089CD80;

	HudElem_Alloc = (HudElem_Alloc_t)0x000000000071BC20;
	G_MaterialIndex = (G_MaterialIndex_t)0x000000000043C4A0;
	G_LocalizedStringIndex = (G_LocalizedStringIndex_t)0x0000000000442410;
	HudElem_DestroyAll = (HudElem_DestroyAll_t)0x000000000071BE00;
	
	
	//AimTarget_GetTagPos = (AimTarget_GetTagPos_t)vHandler->addresses.addr_AimTarget_GetTagPos;
	//AimTarget_IsTargetVisible = (AimTarget_IsTargetVisible_t)vHandler->addresses.addr_AimTarget_IsTargetVisible;

	//CG_CanSeeFriendlyHeadTrace = (CG_CanSeeFriendlyHeadTrace_t)0x00;
	//CG_DObjGetWorldTagPos = (CG_DObjGetWorldTagPos_t)0x00;
	//CG_DrawRotatedPicPhysical = (CG_DrawRotatedPicPhysical_t)vHandler->addresses.addr_CG_DrawRotatedPicPhysical;
	//CG_TracePoint = (CG_TracePoint_t)0x00;

	//CL_DrawText = (CL_DrawText_t)0x00;

	//DB_FindXAssetHeader = (DB_FindXAssetHeader_t)0x00;

	//R_AddCmdDrawQuadPicW = (R_AddCmdDrawQuadPicW_t)vHandler->addresses.addr_R_AddCmdDrawQuadPicW;

	//SL_GetStringOfSize = (SL_GetStringOfSize_t)0x00;

	//UI_DrawText = (UI_DrawText_t)vHandler->addresses.addr_UI_DrawText;
	//UI_FillRectPhysical = (UI_FillRectPhysical_t)vHandler->addresses.addr_UI_FillRectPhysical;

	//sub_E9F770 = (sub_E9F770_t)0x0000000000E87130;
}

END
