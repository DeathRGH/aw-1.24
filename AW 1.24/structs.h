#pragma once

#include "defines.h"
#include "sparse.h"

typedef unsigned short scr_entref_t;
typedef unsigned short scr_string_t;

//

enum GfxRenderCommand : int {
	//...
};

enum LocalClientNum_t : int {
	INVALID_LOCAL_CLIENT = -1,
	LOCAL_CLIENT_0 = 0,
	LOCAL_CLIENT_FIRST = 0,
	LOCAL_CLIENT_1 = 1,
	LOCAL_CLIENT_2 = 2,
	LOCAL_CLIENT_3 = 3,
	LOCAL_CLIENT_COUNT = 5
};

enum svscmd_type : int {
	SV_CMD_CAN_IGNORE = 0,
	SV_CMD_RELIABLE = 1
};


//

struct Font_s { // 0x28
	const char *name;
	int height;
	int u1;
	uintptr_t u2;
	uintptr_t glow;
	uintptr_t u3;
};

struct gentity_s {

};

struct Material {
	const char *name;
};











enum eFlag_t {
	ENTITY_FLAG_CROUCHED = 0x04,
	ENTITY_FLAG_PRONE = 0x08,
	ENTITY_FLAG_SPRINTING = 0x20000,
	ENTITY_FLAG_MANTLEING = 0x28000,
	ENTITY_FLAG_ADS = 0x80000
};

enum eModes : int {
	MODE_ZOMBIES = 0x0,
	MODE_MULTIPLAYER = 0x1,
	MODE_CAMPAIGN = 0x2,
	MODE_WARZONE = 0x3,
	MODE_COUNT = 0x4,
	MODE_INVALID = 0x4,
	MODE_FIRST = 0x0,
};


enum ucmdButtonFlag_t {
	UCMD_BTN_R2 = 0x80000000,
};

enum entityType_t {
	ET_GENERAL = 0x00,
	ET_PLAYER = 0x01,
	ET_PLAYER_CORPSE = 0x02, //
	ET_ITEM = 0x03, //
	ET_MISSILE = 0x04,
	ET_PLAYER_INVISIBLE = 0x05, //
	ET_SCRIPTMOVER = 0x06,
	//ET_SOUND_BLEND = 0x07, //
	//ET_FX = 0x08, //
	//ET_LOOP_FX = 0x09, //
	//ET_PRIMARY_LIGHT = 0x0A, //
	//ET_LENSFLARE = 0x0B, //
	//ET_REFLECTION_PROBE = 0x0C, //
	//ET_HELICOPTER = 0x0D, //
	//ET_PLANE = 0x0E, //
	ET_VEHICLE = 0x0C,
	//ET_VEHICLE_SPAWNER = 0x10, //
	//ET_VEHICLE_CORPSE = 0x11, //
	ET_ACTOR = 0x0F,
	ET_ACTOR_SPAWNER = 0x10,
	ET_ACTOR_CORPSE = 0x11,
	ET_STREAMER_HINT = 0x12, //
	ET_ZBARRIER = 0x13,
	ET_TRIGGER = 0x14, //
	ET_EVENTS = 0x18 //
};

struct ScreenPlacement //size = 0x74
{
	float scaleVirtualToReal[2];	//0x00
	float scaleVirtualToFull[2];	//0x08
	float scaleRealToVirtual[2];	//0x10
	float virtualViewableMin[2];	//0x18
	float virtualViewableMax[2];	//0x20
	float virtualTweakableMin[2];	//0x28
	float virtualTweakableMax[2];	//0x30
	float realViewportBase[2];		//0x38
	float realViewportSize[2];		//0x40
	float realViewportMid[2];		//0x48
	float realViewableMin[2];		//0x50
	float realViewableMax[2];		//0x58
	float realTweakableMin[2];		//0x60
	float realTweakableMax[2];		//0x68
	float hudSplitscreenScale;		//0x70
};

struct UiContext_t {
	int contextIndex;
	int realTime;
	int frameTime;
	int cursorX;
	int cursorY;
	bool isCursorVisible;
	float FPS;
	int frameTimeHistory[4];
};


//


struct clientInfo_t {
	int clientNum;
	int team;
	const char *name;
	short health;
	short maxHealth;
};

struct refdef_t {
	int width;
	int height;
	int sceneResolutionIndex;
	int sceneResolutionIndexHistory[4];
	float tanHalfFovX;
	float tanHalfFovY;
	float vieworg[3];
	float lastvieworg[3];
	float viewaxis[3][3];
	int frametime;
	int time;
};

struct cg_t {
	int clientNum;
	int localClientNum;
	int ping;
	float origin[3];
	clientInfo_t clientInfo[18];
	refdef_t refdef;
};


//


struct cgs_t {
	int screenWidth;
	int screenHeight;
	float aspectRatio;
	const char *gametype;
	const char *hostname;
	int maxClients;
	const char *mapname_d3dbsp;
	const char *mapname;
};


//


struct LerpEntityState_t {
	int eFlags;
	int eFlags2;
	float origin[3];
	float viewAngles[3];
};

struct entityState_t {
	int number;
	LerpEntityState_t lerp;
	short eType;
};

struct centity_t {
	float origin[3];
	float viewAngles[3];
	int state;
	int stateFlag;
	int weapon;
	entityState_t nextState;
	int alive;
	uint64_t __address;
};


//


struct game_button_bits_t {
	int array[3];
};

struct usercmd_t {
	int serverTime;
	game_button_bits_t button_bits;
	int angles[3];
	char forwardmove;
	char rightmove;
	int weapon;
	uint64_t __index;
};

struct clientActive_t {
	float deltaAngles[3];
	int serverId;
	const char *mapname;
	float viewangles[3];
	usercmd_t cmds[128];
	int cmdNumber;
};


//

extern UiContext_t UiContext;
extern cg_t cg;
extern cgs_t cgs;
extern centity_t centity[2048];
extern clientActive_t clientActive;

void ReadStructs();

bool IsAlive(int i);
