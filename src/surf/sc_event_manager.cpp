#include "sc_event_manager.h"

std::unordered_map<EventID, Event*> g_umpEventManager;
std::queue<std::function<void()>> g_qEventsInit;

GAME_EVENT(player_spawn, EventID::PLAYER_SPAWN)
{
	CBasePlayerController* pController = static_cast<CBasePlayerController*>(pEvent->GetPlayerController("userid"));

	//if (!pController  || pController->m_steamID() == 0)
	if (!pController)
		return false;

	g_SurfPlugin.NextFrame([hController = CHandle<CBasePlayerController>(pController)]()
		{
			CCSPlayerController* pController = static_cast<CCSPlayerController*>(hController.Get());
			if (!pController)
				return;

			CCSPlayerPawnBase* pPawn = pController->m_hPawn();
			if (!pPawn || (pPawn->m_lifeState() != LifeState_t::LIFE_ALIVE))
				return;

			pPawn->m_pCollision->m_CollisionGroup() = COLLISION_GROUP_DEBRIS;
			utils::EntityCollisionRulesChanged(pPawn);

			Color colorteam;
			int alpha = pPawn->m_clrRender().a();

			switch (pPawn->m_iTeamNum)
			{
			case CS_TEAM_CT:
			{
				colorteam.SetColor(0, 0, 255, alpha);
				break;
			}

			case CS_TEAM_T:
			{
				colorteam.SetColor(255, 0, 0, alpha);
				break;
			}
			}

			pPawn->m_clrRender(colorteam);

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