#pragma once
// Suppress HL2SDK related warnings, comment these out if something goes wrong
#ifdef _WIN32
#pragma warning (disable: 4099)
#pragma warning (disable: 4005)
#pragma warning (disable: 4267)
#endif

#include <ISmmPlugin.h>
#include <engine/igameeventsystem.h>
#include <igameevents.h>
#include <iplayerinfo.h>
#include <sh_vector.h>
#include <stdint.h>

#include <deque>
#include <queue>
#include <functional>

#include "entity2/entitysystem.h"
#define MAXPLAYERS 64

extern CEntitySystem *g_pEntitySystem;

#define CS_TEAM_NONE        0
#define CS_TEAM_SPECTATOR   1
#define CS_TEAM_T           2
#define CS_TEAM_CT          3

#ifdef _WIN32
#define ROOTBIN "/bin/win64/"
#define GAMEBIN "/csgo/bin/win64/"
#else
#define ROOTBIN "/bin/linuxsteamrt64/"
#define GAMEBIN "/csgo/bin/linuxsteamrt64/"
#endif

PLUGIN_GLOBALVARS();

// these are for searchability, because static behaves differently in different scopes.
#define internal static // static functions & static global variables
#define local_persist static // static local variables

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef i32 b32; // 32 bit boolean

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

enum EventID : uint16 {
	PLAYER_ACTIVATE = 5,
	PLAYER_CONNECT_FULL = 6,
	PLAYER_CONNECT = 8,

	PLAYER_DISCONNECT = 9,
	PLAYER_SPAWN = 11,
	PLAYER_TEAM = 12,
	PLAYER_DEATH = 53,
	PLAYER_SOUND = 273,

	WEAPON_FIRE = 158,

	ROUND_FREEZE_END = 51,
	ROUND_START = 47,
	ROUND_END = 48,
	
	CS_WIN_PANEL_ROUND = 214,
	CS_ROUND_FINAL_BEEP = 212,
	CS_ROUND_START_BEEP = 213,

	ITEM_PICKUP = 168,

	SWITCH_TEAM = 228,
	EVENT_LAST,
};

void Message(const char* msg, ...);
void Panic(const char* msg, ...);