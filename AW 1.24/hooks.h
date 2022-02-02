#pragma once

#include "global.h"
#include "structs.h"

NAMESPACE(Hooks)

typedef void(*CL_Disconnect_t)(LocalClientNum_t localClientNum, bool deactivateClient);
typedef void(*CL_WritePacket_t)(LocalClientNum_t localClientNum);
typedef void(*DrawClientInfo_t)(LocalClientNum_t localClientNum);

extern CL_Disconnect_t CL_Disconnect_s;
extern CL_WritePacket_t CL_WritePacket_s;
extern DrawClientInfo_t DrawClientInfo_s;

void CL_Disconnect_Hook(LocalClientNum_t localClientNum, bool deactivateClient);
void CL_WritePacket_Hook(LocalClientNum_t localClientNum);
void DrawClientInfo_Hook(LocalClientNum_t localClientNum);

END
