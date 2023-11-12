#include "common.h"
#include "utils/utils.h"
#include "surf.h"
#include "utils/simplecmds.h"
#include "utils/eventlistener.h"
#include "surf/sc_features.h"

#include "tier0/memdbgon.h"

/*
CON_COMMAND_F(sc_spawnprot_color, "Set Spawn Protection color for player", FCVAR_SERVER_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND)
{
	if (args.ArgC() != 3)
	{
		ConColorMsg(Color(255, 0, 0, 255), "Usage: sc_spawnprot_color <r> <g> <b>");
		return;
	}

	int r = V_StringToInt32(args[0], 255);
	int g = V_StringToInt32(args[1], 255);
	int b = V_StringToInt32(args[2], 255);

	g_SpawnProtection.SetSpawnColor(r, g, b);
}

CON_COMMAND_F(sc_spawnprot_time, "Set Spawn Protection time duration", FCVAR_SERVER_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND)
{
	if (args.ArgC() != 1)
	{
		ConColorMsg(Color(255, 0, 0, 255), "Usage: sc_spawnprot_time <time>");
		return;
	}

	int time = V_StringToInt32(args[0], 10);

	g_SpawnProtection.SetTimeProtection(time);
}
*/

internal SCMD_CALLBACK(Command_SCHide)
{
	SURFPlayer *player = SURF::GetSURFPlayerManager()->ToPlayer(controller);
	player->ToggleHide();
	return MRES_SUPERCEDE;
}

internal SCMD_CALLBACK(Command_SCResetScore)
{
	controller->m_pActionTrackingServices()->m_matchStats().m_iKills = 0;
	controller->m_pActionTrackingServices()->m_matchStats().m_iAssists = 0;
	controller->m_pActionTrackingServices()->m_matchStats().m_iDeaths = 0;
	controller->m_pActionTrackingServices()->m_matchStats().m_iDamage = 0;
	controller->m_iScore = 0;
	controller->m_iMVPs = 0;

	utils::EntityCollisionRulesChanged(controller->m_hPawn());

	utils::ClientPrint(controller, MsgDest::HUD_PRINTTALK, " \6[SURF] Your scores have been reset!");
	return MRES_SUPERCEDE;
}

void SURF::misc::RegisterCommands()
{
	scmd::RegisterCmd("hide",	Command_SCHide);
	scmd::RegisterCmd("rs",		Command_SCResetScore);
}

void SURF::misc::OnCheckTransmit(CCheckTransmitInfo **pInfo, int infoCount)
{
	for (int i = 0; i < infoCount; i++)
	{
		// Cast it to our own TransmitInfo struct because CCheckTransmitInfo isn't correct.
		TransmitInfo *pTransmitInfo = reinterpret_cast<TransmitInfo*>(pInfo[i]);
		
		// Find out who this info will be sent to.
		CPlayerSlot targetSlot = pTransmitInfo->m_nClientEntityIndex;
		SURFPlayer *targetPlayer = SURF::GetSURFPlayerManager()->ToPlayer(targetSlot);
		
		// Don't hide if player is dead/spectating or if they aren't hiding other players.
		if (!targetPlayer->hideOtherPlayers) continue;
		if (targetPlayer->GetPawn()->m_lifeState() != LIFE_ALIVE) continue;
		// Loop through the list of players and see if they need to be hidden away from our target player.
		for (int j = 0; j < MAXPLAYERS; j++)
		{
			if (j == targetPlayer->GetController()->entindex()) continue;
			CBasePlayerPawn *pawn = SURF::GetSURFPlayerManager()->players[j]->GetPawn();
			if (!pawn) continue;

			// Hide only teammates
			if (targetPlayer->GetController()->m_iTeamNum.Get() == pawn->m_iTeamNum.Get())
			{
				if (pTransmitInfo->m_pTransmitEdict->IsBitSet(pawn->entindex()))
				{
					pTransmitInfo->m_pTransmitEdict->Clear(pawn->entindex());
				}
			}
		}
	}
}

void SURF::misc::OnClientPutInServer(CPlayerSlot slot)
{
	SURFPlayer *player = SURF::GetSURFPlayerManager()->ToPlayer(slot);
	player->Reset();
}