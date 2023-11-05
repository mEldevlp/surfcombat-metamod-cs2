#include "common.h"
#include "KeyValues.h"
#include "eventlistener.h"
//#include "entity/cbaseplayercontroller.h"

#include "tier0/memdbgon.h"
#include "../surf/surf.h"
#include "../utils/utils.h"
#include "../utils/ctimer.h"

extern IServerGameClients* g_pSource2GameClients;
extern CEntitySystem* g_pEntitySystem;
extern CGlobalVars* gpGlobals;
extern IGameEventManager2* g_gameEventManager;

CUtlVector<CGameEventListener*> g_vecEventListeners;

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
	utils::ClientPrintAll(MsgDest::HUD_PRINTTALK, " \5[EVENT] player_spawn");

	CCSPlayerController* pController = (CCSPlayerController*)pEvent->GetPlayerController("userid");

	if (!pController)
		return;

	CBasePlayerPawn* pPawn = pController->m_hPawn();

	if (!pPawn || !pPawn->m_lifeState == LifeState_t::LIFE_ALIVE)
		return;

	pPawn->m_iHealth = 1337;
}

GAME_EVENT_F(round_prestart)
{
	utils::ClientPrintAll(MsgDest::HUD_PRINTTALK, " \5[EVENT] round_prestart");
}

GAME_EVENT_F(player_team)
{
	utils::ClientPrintAll(MsgDest::HUD_PRINTTALK, " \5[EVENT] player_team");
}

GAME_EVENT_F(player_hurt)
{
	utils::ClientPrintAll(MsgDest::HUD_PRINTTALK, " \5[EVENT] player_hurt");
}

GAME_EVENT_F(round_start)
{
	utils::ClientPrintAll(MsgDest::HUD_PRINTTALK, " \5[EVENT] round_start");
}

GAME_EVENT_F(round_end)
{
	utils::ClientPrintAll(MsgDest::HUD_PRINTTALK, " \5[EVENT] round_end");
}