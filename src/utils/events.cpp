#include "common.h"
#include "KeyValues.h"
#include "eventlistener.h"
//#include "entity/cbaseplayercontroller.h"

#include "tier0/memdbgon.h"
#include "../surf/surf.h"
#include "../utils/utils.h"

extern IServerGameClients* g_pSource2GameClients;
extern CEntitySystem* g_pEntitySystem;
extern CGlobalVars* gpGlobals;

CUtlVector<CGameEventListener*> g_vecEventListeners;
IGameEventManager2* g_gameEventManager;

void RegisterEventListeners()
{
	static bool bRegistered = false;

	if (bRegistered || !g_gameEventManager)
		return;

	FOR_EACH_VEC(g_vecEventListeners, i)
	{
		g_gameEventManager->AddListener(g_vecEventListeners[i], g_vecEventListeners[i]->GetEventName(), true);
	}

	bRegistered = true;
}

void UnregisterEventListeners()
{
	if (!g_gameEventManager)
		return;

	FOR_EACH_VEC(g_vecEventListeners, i)
	{
		g_gameEventManager->RemoveListener(g_vecEventListeners[i]);
	}

	g_vecEventListeners.Purge();
}

GAME_EVENT_F(player_spawn)
{
	utils::PrintConsoleAll(" \5[EVENT] player_spawn");
}

GAME_EVENT_F(round_prestart)
{
	utils::PrintConsoleAll(" \5[EVENT] round_prestart");
}

GAME_EVENT_F(player_team)
{
	utils::PrintConsoleAll(" \5[EVENT] player_team");
}

GAME_EVENT_F(player_hurt)
{
	utils::PrintConsoleAll(" \5[EVENT] player_hurt");
}

GAME_EVENT_F(round_start)
{
	utils::PrintConsoleAll(" \5[EVENT] round_start");
}

GAME_EVENT_F(round_end)
{
	utils::PrintConsoleAll(" \5[EVENT] round_end");
}