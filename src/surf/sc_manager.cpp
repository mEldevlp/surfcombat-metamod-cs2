#include "surf.h"

#include "tier0/memdbgon.h"
CSURFPlayerManager g_SURFPlayerManager;
CMovementPlayerManager *g_pPlayerManager = dynamic_cast<CMovementPlayerManager *>(&g_SURFPlayerManager);

CSURFPlayerManager* SURF::GetSURFPlayerManager()
{
	return static_cast<CSURFPlayerManager *>(g_pPlayerManager);
}

SURFPlayer *CSURFPlayerManager::ToPlayer(CCSPlayer_MovementServices *ms)
{
	return static_cast<SURFPlayer *>(CMovementPlayerManager::ToPlayer(ms));
}

SURFPlayer *CSURFPlayerManager::ToPlayer(CCSPlayerController *controller)
{
	return static_cast<SURFPlayer *>(CMovementPlayerManager::ToPlayer(controller));
}

SURFPlayer *CSURFPlayerManager::ToPlayer(CBasePlayerPawn *pawn)
{
	return static_cast<SURFPlayer *>(CMovementPlayerManager::ToPlayer(pawn));
}

SURFPlayer *CSURFPlayerManager::ToPlayer(CPlayerSlot slot)
{
	return static_cast<SURFPlayer *>(CMovementPlayerManager::ToPlayer(slot));
}

SURFPlayer *CSURFPlayerManager::ToPlayer(CEntityIndex entIndex)
{
	return static_cast<SURFPlayer *>(CMovementPlayerManager::ToPlayer(entIndex));
}

SURFPlayer *CSURFPlayerManager::ToPlayer(CPlayerUserId userID)
{
	return static_cast<SURFPlayer *>(CMovementPlayerManager::ToPlayer(userID));
}