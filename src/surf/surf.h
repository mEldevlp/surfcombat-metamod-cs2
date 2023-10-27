#pragma once

#include "common.h"
#include "movement/movement.h"
#include "utils/datatypes.h"

#define SURF_COLLISION_GROUP_STANDARD LAST_SHARED_COLLISION_GROUP
#define SURF_COLLISION_GROUP_NOTRIGGER COLLISION_GROUP_DEBRIS

extern CMovementPlayerManager *g_pPlayerManager;

class SURFPlayer : public MovementPlayer
{
public:

	SURFPlayer(i32 i) : MovementPlayer(i)
	{
		inNoclip = false;
		inNoAngle = false;
		m_currentCpIndex = 0;
		m_checkpoints = CUtlVector<Checkpoint>(1, 0);
	}

	virtual void Reset() override;
	virtual void OnStartProcessMovement() override;
	virtual void OnStopProcessMovement() override;
	virtual void OnStartTouchGround() override;
	
	bool inNoclip;
	bool inNoAngle;

	QAngle lastAngles;

public:
	void ToggleHide();
	void DisableNoclip();
	void ToggleNoclip();
	void EnableGodMode();
	void HandleMoveCollision();
	void UpdatePlayerModelAlpha();
	void SetCheckpoint();
	void TpToCheckpoint();
	void TpToPrevCp();
	void TpToNextCp();
	void ToggleInStrafe();
	
	struct Checkpoint
	{
		Vector origin;
		QAngle angles;
		Vector velocity;
	};
	
	i32 m_currentCpIndex;
	bool hideOtherPlayers;
	CUtlVector<Checkpoint> m_checkpoints;
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
	SURFPlayer *ToPlayer(CCSPlayer_MovementServices *ms);
	SURFPlayer *ToPlayer(CCSPlayerController *controller);
	SURFPlayer *ToPlayer(CBasePlayerPawn *pawn);
	SURFPlayer *ToPlayer(CPlayerSlot slot);
	SURFPlayer *ToPlayer(CEntityIndex entIndex);
	SURFPlayer *ToPlayer(CPlayerUserId userID);
	
	SURFPlayer *ToSURFPlayer(MovementPlayer *player) { return static_cast<SURFPlayer *>(player); }
};

namespace SURF
{
	CSURFPlayerManager *GetSURFPlayerManager();
	namespace HUD
	{
		void OnProcessUsercmds_Post(CPlayerSlot &slot, bf_read *buf, int numcmds, bool ignore, bool paused);
		void DrawSpeedPanel(SURFPlayer *player);
	}
	namespace misc
	{
		void RegisterCommands();
		void OnCheckTransmit(CCheckTransmitInfo **pInfo, int infoCount);
		void OnClientPutInServer(CPlayerSlot slot);
	}
};