#include "host.h"

#include "functions.h"
#include "imports.h"

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
NAMESPACE(Entity)

gentity_s *GetEntityPtr(int i) {
	return (gentity_s *)(gentity_t + (i * gentity_size));
}

gentity_s *SpawnScriptModel(const char *modelName, float *origin) {
	gentity_s *entity = G_Spawn();
	if (entity) {
		if (modelName)
			G_SetModel(entity, modelName);

		if (origin)
			G_SetOrigin(entity, origin);

		//entity->spawnflags = 0;
		SP_script_model(entity);
	}

	return entity;
}

void CloneBrushModelToScriptModel(gentity_s *scriptModel, gentity_s *brushModel) {
	if (!scriptModel || !brushModel)
		return;

	SV_UnlinkEntity(scriptModel);
	*(int *)((uint8_t *)scriptModel + /*0x8C*/0xE0) = *(int *)((uint8_t *)brushModel + /*0x8C*/0xE0); // s.index.brushModel
	*(uint8_t *)((uint8_t *)scriptModel + /*0x109*/0x101) = 4; // r.modelType
	int contents = *(int *)((uint8_t *)scriptModel + 0x11C); // r.contents
	SV_SetBrushModel(scriptModel);
	*(int *)((uint8_t *)scriptModel + 0x11C) |= contents; // r.contents
	SV_LinkEntity(scriptModel);
}

int Solid(gentity_s *ent) {
	int *scrconst = (int *)scr_const;
	int classname = ent->classname;
	if (classname != *(scrconst + 0x57)) { //ScriptEntCmd_Solid + 0x6C   cmp eax, [rcx+15Ch]   (0x15C / 4)
		if (classname == *(scrconst + 0x56)) { //ScriptEntCmd_Solid + 0x7B   cmp eax, [rcx+158h]   (0x158 / 4)
			*(int *)((uint8_t *)ent + 0x11C) = 0x2080; // r.contents
		}
		else {
			*(int *)((uint8_t *)ent + 0x11C) = 1; // r.contents
			*(uint8_t *)((uint8_t *)ent + 0x58) &= 0xFE; // s.lerp.eFlags
		}

		SV_LinkEntity(ent);
		return 0;
	}
	else
		return 1;
}

gentity_s *FindCollision(const char *name) {
	for (int i = 0; i < 256; i++) {
		gentity_s *ent = GetEntityPtr(i);
		// check if it is a brushmodel
		if (*(uint8_t *)((uint8_t *)ent + /*0x109*/0x101) == 4) {
			const char *targetname = SL_ConvertToString(ent->targetname);
			if (targetname) {
				// see d3dbsp files for maps
				if (!strcmp(targetname, name)) {
					return ent;
				}
			}
		}
	}

	return 0;
}

const char *GetModelNameFromEntity(int i) {
	gentity_s *ent = GetEntityPtr(i);

	unsigned int modelNameIndex = G_ModelName(ent->modelIndex);
	return SL_ConvertToString((scr_string_t)modelNameIndex);
}

const char *GetModelNameFromEntity(gentity_s *ent) {
	unsigned int modelNameIndex = G_ModelName(ent->modelIndex);
	return SL_ConvertToString((scr_string_t)modelNameIndex);
}

END
NAMESPACE(Menu)

int lastClientButton[MAX_MENU_CLIENTS];

END
END
