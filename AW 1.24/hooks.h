#pragma once

#include "global.h"
#include "structs.h"

NAMESPACE(Hooks)

typedef void(*CL_Disconnect_t)(LocalClientNum_t localClientNum, bool deactivateClient);

extern CL_Disconnect_t CL_Disconnect_Stub;

typedef void(*LUIElement_Render_t)(LocalClientNum_t, void *, void *, void *, int, void *, float);
extern LUIElement_Render_t LUIElement_Render_Stub;

//

void CL_Disconnect_Hook(LocalClientNum_t localClientNum, bool deactivateClient);

void LUI_Interface_DebugPrint_Hook(const char *fmt, ...);

void LUIElement_Render_Hook(LocalClientNum_t rdi, LUIElement *rsi, LUIElement *rdx, RootUserData *rcx, int r8d, lua_State *r9, float xmm0);

void R_EndFrame_Hook();

void Scr_Notify_Hook(gentity_s *ent, scr_string_t stringValue, unsigned int paramcount);

END
