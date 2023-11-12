#include "surf.h"
#include "utils/utils.h"
#include "igameevents.h"
#include "tier0/memdbgon.h"

static const Vector NULL_VECTOR = Vector(0, 0, 0);

void SURFPlayer::EnableGodMode()
{
	//todo: no fall damage

	/* 
	CCSPlayerPawn *pawn = this->GetPawn();
	if (!pawn) return;
	if (pawn->m_bTakesDamage())
	{
		pawn->m_bTakesDamage(false);
	}
	*/
}

void SURFPlayer::OnStartTouchGround()
{
	
}

void SURFPlayer::OnStopTouchGround()
{
}

void SURFPlayer::OnAirAcceleratePre(Vector &wishdir, f32 &wishspeed, f32 &accel)
{
}

void SURFPlayer::OnAirAcceleratePost(Vector wishdir, f32 wishspeed, f32 accel)
{
}

void SURFPlayer::HandleMoveCollision()
{
	CCSPlayerPawn *pawn = this->GetPawn();
	if (!pawn) return;
	if (pawn->m_lifeState() != LIFE_ALIVE)
	{
		DisableNoclip();
		return;
	}
	if (this->inNoclip)
	{
		if (pawn->m_MoveType() != MOVETYPE_NOCLIP)
		{
			utils::SetEntityMoveType(pawn, MOVETYPE_NOCLIP);
		}
		if (pawn->m_Collision().m_CollisionGroup() != COLLISION_GROUP_STANDARD)
		{
			pawn->m_Collision().m_CollisionGroup() = COLLISION_GROUP_STANDARD;
			utils::EntityCollisionRulesChanged(pawn);
		}
	}
	else
	{
		if (pawn->m_MoveType() == MOVETYPE_NOCLIP)
		{
			utils::SetEntityMoveType(pawn, MOVETYPE_WALK);
		}
		if (pawn->m_Collision().m_CollisionGroup() != COLLISION_GROUP_NOTRIGGER)
		{
			pawn->m_Collision().m_CollisionGroup() = COLLISION_GROUP_NOTRIGGER;
			utils::EntityCollisionRulesChanged(pawn);
		}
	}
}

void SURFPlayer::UpdatePlayerModelAlpha()
{
	CCSPlayerPawn *pawn = this->GetPawn();
	if (!pawn) return;

	Color ogColor = pawn->m_clrRender();
	if (pawn->m_clrRender().a() != 254)
	{
		pawn->m_clrRender(Color(255, 255, 255, 254));
	}
	else
	{
		pawn->m_clrRender(Color(255, 255, 255, 255));
	}
}

void SURFPlayer::ToggleNoclip()
{
	this->inNoclip = !this->inNoclip;
}

void SURFPlayer::DisableNoclip()
{
	this->inNoclip = false;
}

void SURFPlayer::OnStartProcessMovement()
{
	MovementPlayer::OnStartProcessMovement();
	// Always ensure that the player has at least an ongoing jump.
	// This is mostly to prevent crash, it's not a valid jump.

	//this->EnableGodMode();
	//this->HandleMoveCollision();
}

void SURFPlayer::OnStopProcessMovement()
{
	SURF::HUD::DrawSpeedPanel(this);

	MovementPlayer::OnStopProcessMovement();
}

void SURFPlayer::ToggleHideLegs()
{
	this->hidePlayerLegs = !this->hidePlayerLegs;
}

void SURFPlayer::ToggleHide()
{
	this->hideOtherPlayers = !this->hideOtherPlayers;
}

void SURFPlayer::Reset()
{
	MovementPlayer::Reset();

	this->currentCpIndex = 0;
	this->hideOtherPlayers = false;
	this->holdingStill = false;
	this->teleportTime = 0.0f;
}