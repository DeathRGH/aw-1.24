#include "hooks.h"

#include "cache.h"
#include "defines.h"
#include "functions.h"
#include "global.h"
#include "menuoptions.h"
#include "offhost.h"
#include "structs.h"
#include "utility.h"

NAMESPACE(Hooks)

CL_Disconnect_t CL_Disconnect_s;
CL_WritePacket_t CL_WritePacket_s;
DrawClientInfo_t DrawClientInfo_s;

void CL_Disconnect_Hook(LocalClientNum_t localClientNum, bool deactivateClient) {
	CreateThread((void *)PreventCrash, "preventCrash");

	CL_Disconnect_s(localClientNum, deactivateClient);
}

void CL_WritePacket_Hook(LocalClientNum_t localClientNum) {
	ReadStructs();
	//Cache::CacheAll();

	//AimbotLoop();

	CL_WritePacket_s(localClientNum);
}

void DrawClientInfo_Hook(LocalClientNum_t localClientNum) {
	DrawClientInfo_s(localClientNum);

	if (!ShouldRun())
		return;

	/*threadReturnClient = -1;
	ReadStructs();

	Cache::CacheAll();

	LoopSettings();

	MonitorButtons();
	
	AimbotCalculation();

	DrawCustomCrosshair();

	DrawInfoBoxes();
	DrawMenu();

	DrawBuildNumber();*/

	//DrawHexDump(1000.0f, 800.0f, 0x400000, 0x100, 0.4f);
}

END
