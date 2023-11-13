#include "surf.h"
#include "utils/utils.h"

#include "tier0/memdbgon.h"

void SURF::HUD::OnProcessUsercmds_Post(CPlayerSlot &slot, bf_read *buf, int numcmds, bool ignore, bool paused)
{
}

internal void AddSpeedText(SURFPlayer *player, char* buffer, int size)
{
	char speed[128];
	speed[0] = 0;
	Vector velocity;
	player->GetVelocity(&velocity);

	snprintf(speed, sizeof(speed), "Speed: %.0f          ", velocity.Length2D());

	strncat(buffer, speed, size);
}

internal void AddKeyText(SURFPlayer *player, char *buffer, int size)
{
	char keys[128];
	keys[0] = 0;

	snprintf(keys, sizeof(keys), "Keys:  %s %s %s\n                                     %s %s %s",
		player->IsButtonDown(IN_TURNLEFT) ? "+L" : "_",
		player->IsButtonDown(IN_FORWARD) ? "W" : "_",
		player->IsButtonDown(IN_TURNRIGHT) ? "+R" : "_",
		player->IsButtonDown(IN_MOVELEFT) ? "A" : "_",
		player->IsButtonDown(IN_BACK) ? "S" : "_",
		player->IsButtonDown(IN_MOVERIGHT) ? "D" : "_");

	strncat(buffer, keys, size);
}

void SURF::HUD::DrawSpeedPanel(SURFPlayer *player)
{
	char buffer[1024];
	buffer[0] = 0;
	AddSpeedText(player, buffer, sizeof(buffer));
	AddKeyText(player, buffer, sizeof(buffer));


	//utils::PrintAlert(static_cast<CBasePlayerController*>(player->GetController()), "%s", buffer);
}