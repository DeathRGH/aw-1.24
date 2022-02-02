#include "host.h"

#include "functions.h"
#include "imports.h"
#include "structs.h"

NAMESPACE(Host)

void FireMagicBullet(short entNum, const char *projectile) {
	float playerAngles[3];
	playerAngles[0] = *(float *)((entNum * 0x5780) + 0x000000000659C180 + 0x1B4);
	playerAngles[1] = *(float *)((entNum * 0x5780) + 0x000000000659C180 + 0x1B4 + 4);
	playerAngles[2] = *(float *)((entNum * 0x5780) + 0x000000000659C180 + 0x1B4 + 8);

	float forward[3];
	AngleVectors(playerAngles, forward, 0, 0);
	forward[0] *= 999999999.0f;
	forward[1] *= 999999999.0f;
	forward[2] *= 999999999.0f;

	float startPos[3];
	G_DObjGetWorldTagPos((gentity_s *)0x00000000064293D0 + (entNum * 0x2E0), SL_GetString("tag_weapon_right", 0), startPos);

	Scr_AddVector(forward);
	Scr_AddVector(startPos);
	Scr_AddString(projectile);
	Scr_SetNumParam(3);

	Scr_MagicBullet();
}

NAMESPACE(Lobby)

void Godmode(bool state) {
	memcpy((void *)0x00000000007138BA, state ? "\x90\x90\x90\x90\x90\x90\x90" : "\x45\x29\xA7\xD0\x01\x00\x00", 7);
}

void InfiniteAmmo(bool state) {
	memcpy((void *)0x00000000005768EF, state ? "\x90\x90\x90\x90\x90" : "\x44\x29\x7C\x81\x08", 5);
}

END
END
