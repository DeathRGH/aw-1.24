#include "cache.h"

#include "defines.h"
#include "imports.h"
#include "structs.h"

NAMESPACE(Cache)

Game_s Game;

void CacheGame() {
	Game.inGame = InGame();
	Game.gametype = Game.inGame ? GetRawGametype() : "Unknown";
	Game.mapname = Game.inGame ? GetRawMapname() : "Unknown";
	Game.hostname = Game.inGame ? cgs.hostname : "Unknown Host";
	Game.inZombies = !strcmp(Game.gametype, "zclassic"); //needs additional checks (dump rush gametype, ...)
	Game.inWZ = !strcmp(Game.gametype, "warzone_solo") || !strcmp(Game.gametype, "warzone_duo") || !strcmp(Game.gametype, "warzone_quad");
}

void CacheAll() {
	CacheGame();
}

END
