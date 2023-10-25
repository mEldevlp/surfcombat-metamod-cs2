#pragma once

#ifdef _WIN32
#pragma warning (disable: 4099)
#pragma warning (disable: 4005)
#pragma warning (disable: 4267)
#endif

#include <stdint.h>

// Metamod:Source
#include <ISmmPlugin.h>
#include <sh_vector.h>

// Valve Corporation
#include "iserver.h"
#include <iplayerinfo.h>
#include <igameevents.h>

// other
#include <datatypes.h>


// Surf Combat
#include "sc_main.h"


#define MAXPLAYERS 64

#ifdef _WIN32
#define ROOTBIN "/bin/win64/"
#define GAMEBIN "/csgo/bin/win64/"
#else
#define ROOTBIN "/bin/linuxsteamrt64/"
#define GAMEBIN "/csgo/bin/linuxsteamrt64/"
#endif

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