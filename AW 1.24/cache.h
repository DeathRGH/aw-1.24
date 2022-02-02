#pragma once

#include "global.h"

NAMESPACE(Cache)

struct Game_s {
	bool inGame;
	const char *gametype;
	const char *mapname;
	const char *hostname;
	bool inZombies;
	bool inWZ;
};
extern Game_s Game;

void CacheGame();

void CacheAll();

END
