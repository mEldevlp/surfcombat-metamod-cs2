#pragma once

#include "common.h"
#include "movement/movement.h"
#include "utils/datatypes.h"

#define COLLISION_GROUP_STANDARD LAST_SHARED_COLLISION_GROUP
#define COLLISION_GROUP_NOTRIGGER COLLISION_GROUP_DEBRIS

extern CMovementPlayerManager *g_pPlayerManager;

class SURFPlayer;

class SURFPlayer : public MovementPlayer
{
public:
	SURFPlayer(i32 i) : MovementPlayer(i) {}
	virtual void Reset() override;
	virtual void OnStartProcessMovement() override;
	virtual void OnStopProcessMovement() override;
	virtual void OnAirAcceleratePre(Vector &wishdir, f32 &wishspeed, f32 &accel) override;
	virtual void OnAirAcceleratePost(Vector wishdir, f32 wishspeed, f32 accel) override;
	virtual void OnStartTouchGround() override;
	virtual void OnStopTouchGround() override;
private:
	bool inNoclip;
	TurnState previousTurnState;
public:
	void ToggleHide();
	void DisableNoclip();
	void ToggleNoclip();
	void EnableGodMode();
	void HandleMoveCollision();
	void UpdatePlayerModelAlpha();
	
	i32 currentCpIndex{};
	bool holdingStill{};
	f32 teleportTime{};

	void SetCheckpoint();
	void DoTeleport(i32 index);
	void TpHoldPlayerStill();
	void TpToCheckpoint();
	void TpToPrevCp();
	void TpToNextCp();

	// misc
	bool hideOtherPlayers{};
};

class CSURFPlayerManager : public CMovementPlayerManager
{
public:
	CSURFPlayerManager()
	{
		for (int i = 0; i < MAXPLAYERS + 1; i++)
		{
			delete players[i];
			players[i] = new SURFPlayer(i);
		}
	}
public:
	SURFPlayer* ToPlayer(CCSPlayer_MovementServices *ms);
	SURFPlayer* ToPlayer(CCSPlayerController *controller);
	SURFPlayer* ToPlayer(CBasePlayerPawn *pawn);
	SURFPlayer* ToPlayer(CPlayerSlot slot);
	SURFPlayer* ToPlayer(CEntityIndex entIndex);
	SURFPlayer* ToPlayer(CPlayerUserId userID);

	SURFPlayer* ToSURFPlayer(MovementPlayer *player) { return static_cast<SURFPlayer*>(player); }
};

namespace SURF
{
	CSURFPlayerManager* GetSURFPlayerManager();
	namespace HUD
	{
		void OnProcessUsercmds_Post(CPlayerSlot &slot, bf_read *buf, int numcmds, bool ignore, bool paused);
		void DrawSpeedPanel(SURFPlayer*player);
	}
	namespace misc
	{
		void RegisterCommands();
		void OnCheckTransmit(CCheckTransmitInfo **pInfo, int infoCount);
		void OnClientPutInServer(CPlayerSlot slot);
	}
};