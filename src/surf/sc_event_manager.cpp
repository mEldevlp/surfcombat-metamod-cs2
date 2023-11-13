#include "sc_event_manager.h"
#include "sc_features.h"

std::unordered_map<EventID, Event*> g_umpEventManager;
std::queue<std::function<void()>> g_qEventsInit;

GAME_EVENT(player_spawn, EventID::PLAYER_SPAWN)
{
	CBasePlayerController* pController = static_cast<CBasePlayerController*>(pEvent->GetPlayerController("userid"));

	if (!pController)
		return false;

	CCSPlayerPawnBase* pPawn = pController->m_hPawn();
	if (!pPawn || (pPawn->m_lifeState() != LifeState_t::LIFE_ALIVE))
		return false;

	g_SurfPlugin.NextFrame([pPawn]()
		{
			pPawn->m_bTakesDamage(false);
			pPawn->m_clrRender(g_SpawnProtection.GetSpawnColor());
			pPawn->m_pCollision->m_CollisionGroup = COLLISION_GROUP_DEBRIS;
			pPawn->m_pCollision->m_collisionAttribute().m_nCollisionGroup = COLLISION_GROUP_DEBRIS;
			utils::EntityCollisionRulesChanged(pPawn);
		});

	utils::ClientPrint(pController, MsgDest::HUD_PRINTCENTER, "Spawn Protection %d sec.", (int)g_SpawnProtection.GetTimeProtection());
	
	new CTimer(g_SpawnProtection.GetTimeProtection() + 1.0f, false, [hController = CHandle<CBasePlayerController>(pController)]()
		{

			CCSPlayerController* pController = static_cast<CCSPlayerController*>(hController.Get());
			if (!pController)
				return -1.0f;

			CCSPlayerPawnBase* pPawn = pController->m_hPawn();
			if (!pPawn || (pPawn->m_lifeState() != LifeState_t::LIFE_ALIVE))
				return -1.0f;

			Color colorteam;
			int alpha = pPawn->m_clrRender().a();

			if (pPawn->m_iTeamNum == CS_TEAM_CT)	 colorteam.SetColor(0, 0, 255, alpha);
			else if (pPawn->m_iTeamNum == CS_TEAM_T) colorteam.SetColor(255, 0, 0, alpha);
			else return -1.0f;

			utils::ClientPrint(pController, MsgDest::HUD_PRINTCENTER, "Protection is gone");
			pPawn->m_clrRender(colorteam);
			pPawn->m_bTakesDamage(true);

			return -1.0f;
		});

	return true;
}

void Init_EventManager()
{
	while (!g_qEventsInit.empty())
	{
		g_qEventsInit.front()();
		g_qEventsInit.pop();
	}
}