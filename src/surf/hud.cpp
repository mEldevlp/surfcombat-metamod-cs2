#include "surf.h"
#include "utils/utils.h"

#include "tier0/memdbgon.h"

void SURF::HUD::OnProcessUsercmds_Post(CPlayerSlot &slot, bf_read *buf, int numcmds, bool ignore, bool paused)
{
}

internal void AddSpeedText(SURFPlayer *player, char* buffer)
{
	char speed[128];
	Vector velocity;
	player->GetVelocity(&velocity);

	snprintf(speed, sizeof(speed), "Speed: %.0f", velocity.Length2D());

	strcat(buffer, speed);
}

internal void AddKeyText(SURFPlayer *player, char *buffer)
{
	char keys[128];

	snprintf(keys, sizeof(keys), "Keys: %s %s %s %s %s %s",
		player->IsButtonDown(IN_MOVELEFT) ? "A" : "_",
		player->IsButtonDown(IN_FORWARD) ? "W" : "_",
		player->IsButtonDown(IN_BACK) ? "S" : "_",
		player->IsButtonDown(IN_MOVERIGHT) ? "D" : "_",
		player->IsButtonDown(IN_DUCK) ? "C" : "_",
		player->IsButtonDown(IN_JUMP) ? "J" : "_");
	/*
	if (!player->inNoclip)
	{

	}
	else
	{
		snprintf(keys, sizeof(keys), "Keys: _ _ _ _ %s %s",
			player->IsButtonDown(IN_DUCK) ? "C" : "_",
			player->IsButtonDown(IN_JUMP) ? "J" : "_");
	}*/

	strcat(buffer, keys);
}

void SURF::HUD::DrawSpeedPanel(SURFPlayer *player)
{
	char buffer[1024] = "";
	AddSpeedText(player, buffer);
	strcat(buffer, "\n"); 
	AddKeyText(player, buffer);

	utils::PrintAlert(g_pEntitySystem->GetBaseEntity(CEntityIndex(player->index)), "%s", buffer);
}