#include "../protobuf/generated/cstrike15_usermessages.pb.h"
#include "../protobuf/generated/usermessages.pb.h"
#include "../protobuf/generated/cs_gameevents.pb.h"
#include "../protobuf/generated/gameevents.pb.h"
#include "../protobuf/generated/te.pb.h"

#include "sc_main.h"

#include "interface.h"
#include "icvar.h"
#include "entity2/entitysystem.h"

#include "common.h"
#include "utils/utils.h"
#include "utils/recipientfilters.h"
#include "utils/detours.h"
#include "utils/addresses.h"
#include "utils/simplecmds.h"

#include "movement/movement.h"
#include "surf/surf.h"
#include "utils/eventlistener.h"

#include "tier0/memdbgon.h"

SurfPlugin g_SurfPlugin;

SH_DECL_HOOK2_void(ISource2GameClients, ClientCommand, SH_NOATTRIB, false, CPlayerSlot, const CCommand&);
SH_DECL_HOOK6_void(ISource2GameEntities, CheckTransmit, SH_NOATTRIB, false, CCheckTransmitInfo**, int, CBitVec<16384>&, const Entity2Networkable_t **, const uint16 *, int);
SH_DECL_HOOK3_void(ISource2Server, GameFrame, SH_NOATTRIB, false, bool, bool, bool);
SH_DECL_HOOK5(ISource2GameClients, ProcessUsercmds, SH_NOATTRIB, false, float, CPlayerSlot, bf_read *, int, bool, bool);
SH_DECL_HOOK2_void(CEntitySystem, Spawn, SH_NOATTRIB, false, int, const EntitySpawnInfo_t *);
SH_DECL_HOOK4_void(ISource2GameClients, ClientPutInServer, SH_NOATTRIB, false, CPlayerSlot, char const *, int, uint64);
SH_DECL_HOOK2(IGameEventManager2, FireEvent, SH_NOATTRIB, 0, bool, IGameEvent*, bool);

IGameEventManager2* g_gameEventManager = nullptr;
CEntitySystem *g_pEntitySystem = nullptr;

PLUGIN_EXPOSE(SurfPlugin, g_SurfPlugin);

bool SurfPlugin::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	PLUGIN_SAVEVARS();
	
	if (!utils::Initialize(ismm, error, maxlen))
	{
		return false;
	}

	movement::InitDetours();

	SH_ADD_HOOK(ISource2GameClients, ClientCommand, g_pSource2GameClients, SH_MEMBER(this, &SurfPlugin::Hook_ClientCommand), false);
	SH_ADD_HOOK(ISource2Server, GameFrame, interfaces::pServer, SH_MEMBER(this, &SurfPlugin::Hook_GameFrame), false);
	SH_ADD_HOOK(ISource2GameClients, ProcessUsercmds, g_pSource2GameClients, SH_MEMBER(this, &SurfPlugin::Hook_ProcessUsercmds_Pre), false);
	SH_ADD_HOOK(ISource2GameClients, ProcessUsercmds, g_pSource2GameClients, SH_MEMBER(this, &SurfPlugin::Hook_ProcessUsercmds_Post), true);
	SH_ADD_HOOK(ISource2GameEntities, CheckTransmit, g_pSource2GameEntities, SH_MEMBER(this, &SurfPlugin::Hook_CheckTransmit), true);
	SH_ADD_HOOK(ISource2GameClients, ClientPutInServer, g_pSource2GameClients, SH_MEMBER(this, &SurfPlugin::Hook_ClientPutInServer), false);
	SH_ADD_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &SurfPlugin::Hook_FireGameEvent), false);

	if (!g_gameEventManager)
	{
		META_CONPRINTF("Failed to find GameEventManager\n");
	}

	//RegisterEventListeners();

	SURF::misc::RegisterCommands();

	return true;
}

bool SurfPlugin::Unload(char *error, size_t maxlen)
{
	SH_REMOVE_HOOK(ISource2GameClients, ClientCommand, g_pSource2GameClients, SH_MEMBER(this, &SurfPlugin::Hook_ClientCommand), false);
	SH_REMOVE_HOOK(ISource2Server, GameFrame, interfaces::pServer, SH_MEMBER(this, &SurfPlugin::Hook_GameFrame), false);
	SH_REMOVE_HOOK(ISource2GameClients, ProcessUsercmds, g_pSource2GameClients, SH_MEMBER(this, &SurfPlugin::Hook_ProcessUsercmds_Pre), false);
	SH_REMOVE_HOOK(ISource2GameClients, ProcessUsercmds, g_pSource2GameClients, SH_MEMBER(this, &SurfPlugin::Hook_ProcessUsercmds_Post), true);
	SH_REMOVE_HOOK(CEntitySystem, Spawn, g_pEntitySystem, SH_MEMBER(this, &SurfPlugin::Hook_CEntitySystem_Spawn_Post), true);
	SH_REMOVE_HOOK(ISource2GameEntities, CheckTransmit, g_pSource2GameEntities, SH_MEMBER(this, &SurfPlugin::Hook_CheckTransmit), true);
	SH_REMOVE_HOOK(ISource2GameClients, ClientPutInServer, g_pSource2GameClients, SH_MEMBER(this, &SurfPlugin::Hook_ClientPutInServer), false);
	SH_REMOVE_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &SurfPlugin::Hook_FireGameEvent), false);

	utils::Cleanup();
	return true;
}

void SurfPlugin::AllPluginsLoaded()
{
}

bool SurfPlugin::Pause(char *error, size_t maxlen)
{
	return true;
}

bool SurfPlugin::Unpause(char *error, size_t maxlen)
{
	return true;
}

const char *SurfPlugin::GetLicense()
{
	return "MIT";
}

const char *SurfPlugin::GetVersion()
{
	return "0.3-a";
}

const char *SurfPlugin::GetDate()
{
	return __DATE__;
}

const char *SurfPlugin::GetLogTag()
{
	return "Surf";
}

const char *SurfPlugin::GetAuthor()
{
	return "\\mEl\\ & zer0.k";
}

const char *SurfPlugin::GetDescription()
{
	return "Surf Combat CS2 Metamod";
}

const char *SurfPlugin::GetName()
{
	return "SURF";
}

const char *SurfPlugin::GetURL()
{
	return "https://github.com/mEldevlp/surfcombat-metamod-cs2";
}

float SurfPlugin::Hook_ProcessUsercmds_Pre(CPlayerSlot slot, bf_read *buf, int numcmds, bool ignore, bool paused)
{
	RETURN_META_VALUE(MRES_IGNORED, 0.0f);
}

float SurfPlugin::Hook_ProcessUsercmds_Post(CPlayerSlot slot, bf_read *buf, int numcmds, bool ignore, bool paused)
{
	SURF::HUD::OnProcessUsercmds_Post(slot, buf, numcmds, ignore, paused);
	RETURN_META_VALUE(MRES_IGNORED, 0.0f);
}

void SurfPlugin::Hook_CEntitySystem_Spawn_Post(int nCount, const EntitySpawnInfo_t *pInfo_DontUse)
{
	/*
	EntitySpawnInfo_t *pInfo = (EntitySpawnInfo_t *)pInfo_DontUse;
	
	for (i32 i = 0; i < nCount; i++)
	{
		if (pInfo && pInfo[i].m_pEntity)
		{

		}
	}
	*/

	RETURN_META(MRES_IGNORED);
}

void SurfPlugin::Hook_GameFrame(bool simulating, bool bFirstTick, bool bLastTick)
{
	if (!g_pEntitySystem)
	{
		g_pEntitySystem = interfaces::pGameResourceServiceServer->GetGameEntitySystem();
		assert(g_pEntitySystem);
		SH_ADD_HOOK(CEntitySystem, Spawn, g_pEntitySystem, SH_MEMBER(this, &SurfPlugin::Hook_CEntitySystem_Spawn_Post), true);
	}
	RETURN_META(MRES_IGNORED);
}

void SurfPlugin::Hook_ClientCommand(CPlayerSlot slot, const CCommand& args)
{
	if (META_RES result = scmd::OnClientCommand(slot, args))
	{
		RETURN_META(result);
	}
	RETURN_META(MRES_IGNORED);
}

void SurfPlugin::Hook_CheckTransmit(CCheckTransmitInfo **pInfo, int infoCount, CBitVec<16384> &, const Entity2Networkable_t **pNetworkables, const uint16 *pEntityIndicies, int nEntities)
{
	SURF::misc::OnCheckTransmit(pInfo, infoCount);
	RETURN_META(MRES_IGNORED);
}

void SurfPlugin::Hook_ClientPutInServer(CPlayerSlot slot, char const *pszName, int type, uint64 xuid)
{
	SURF::misc::OnClientPutInServer(slot);
	RETURN_META(MRES_IGNORED);
}

bool SurfPlugin::Hook_FireGameEvent(IGameEvent* pEvent, bool bDontBroadcast)
{
	if (!pEvent) return false;

	//TODO: make eventsystem by names 
	// g_EventManager[pEvent->GetName()]->DoCallback();

	META_CONPRINTF("%s\n", pEvent->GetName());

	return true;
}