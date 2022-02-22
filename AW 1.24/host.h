#pragma once

#include "global.h"
#include "structs.h"

NAMESPACE(Host)

void FireMagicBullet(short entNum, const char *projectile);

NAMESPACE(Lobby)

void Godmode(bool state);
void InfiniteAmmo(bool state);

END
NAMESPACE(Entity)

gentity_s *GetEntityPtr(int i);
gentity_s *SpawnScriptModel(const char *modelName, float *origin);

const char *GetModelNameFromEntity(int i);
const char *GetModelNameFromEntity(gentity_s *ent);

END
NAMESPACE(Menu)

#define MAX_MENU_CLIENTS 18
extern int lastClientButton[MAX_MENU_CLIENTS];

END
END
