#include "common.h"
#include "utils/utils.h"
#include "surf.h"
#include "utils/simplecmds.h"

#include "tier0/memdbgon.h"

internal SCMD_CALLBACK(Command_SCNoclip)
{
	SURFPlayer *player = SURF::GetSURFPlayerManager()->ToPlayer(controller);
	player->ToggleNoclip();
	return MRES_SUPERCEDE;
}

internal SCMD_CALLBACK(Command_SCHidelegs)
{
	SURFPlayer *player = SURF::GetSURFPlayerManager()->ToPlayer(controller);
	player->UpdatePlayerModelAlpha();
	return MRES_SUPERCEDE;
}

internal SCMD_CALLBACK(Command_SCHide)
{
	SURFPlayer *player = SURF::GetSURFPlayerManager()->ToPlayer(controller);
	player->ToggleHide();
	return MRES_SUPERCEDE;
}

void SURF::misc::RegisterCommands()
{
	scmd::RegisterCmd("sc_noclip",     Command_SCNoclip); // For debug. Not inlcuded in release
	scmd::RegisterCmd("sc_hidelegs",   Command_SCHidelegs);
	scmd::RegisterCmd("sc_hide",	   Command_SCHide);
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
			if (pTransmitInfo->m_pTransmitEdict->IsBitSet(pawn->entindex()))
			{
				pTransmitInfo->m_pTransmitEdict->Clear(pawn->entindex());
			}
		}
	}
}

void SURF::misc::OnClientPutInServer(CPlayerSlot slot)
{
	SURFPlayer *player = SURF::GetSURFPlayerManager()->ToPlayer(slot);
	player->Reset();
}