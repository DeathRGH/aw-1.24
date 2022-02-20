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

gentity_s *GetEntity(int i);
gentity_s *SpawnScriptModel(const char *modelName, float *origin);

END
END
