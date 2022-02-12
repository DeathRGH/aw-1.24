#pragma once

#include "global.h"
#include "structs.h"

NAMESPACE(Hooks)

typedef void(*CL_Disconnect_t)(LocalClientNum_t localClientNum, bool deactivateClient);

extern CL_Disconnect_t CL_Disconnect_Stub;

//

void CL_Disconnect_Hook(LocalClientNum_t localClientNum, bool deactivateClient);

void LUI_Interface_DebugPrint_Hook(const char *fmt, ...);

void R_EndFrame_Hook();

void Scr_Notify_Hook(gentity_s *ent, scr_string_t stringValue, unsigned int paramcount);

END
