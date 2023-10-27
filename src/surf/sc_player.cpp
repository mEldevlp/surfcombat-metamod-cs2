#include "surf.h"
#include "utils/utils.h"

#include "tier0/memdbgon.h"

static const Vector NULL_VECTOR = Vector(0, 0, 0);

void SURFPlayer::EnableGodMode()
{
	CCSPlayerPawn *pawn = this->GetPawn();
	if (!pawn) return;
	if (pawn->m_bTakesDamage())
	{
		pawn->m_bTakesDamage(false);
	}
}

void SURFPlayer::OnStartTouchGround()
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

		if (pawn->m_Collision().m_CollisionGroup() != SURF_COLLISION_GROUP_STANDARD)
		{
			pawn->m_Collision().m_CollisionGroup() = SURF_COLLISION_GROUP_STANDARD;
			utils::EntityCollisionRulesChanged(pawn);
		}
	}
	else
	{
		if (pawn->m_MoveType() == MOVETYPE_NOCLIP)
		{
			utils::SetEntityMoveType(pawn, MOVETYPE_WALK);
		}
		if (pawn->m_Collision().m_CollisionGroup() != SURF_COLLISION_GROUP_NOTRIGGER)
		{
			pawn->m_Collision().m_CollisionGroup() = SURF_COLLISION_GROUP_NOTRIGGER;
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

void SURFPlayer::SetCheckpoint()
{
	CCSPlayerPawn *pawn = this->GetPawn();
	if (!pawn) return;
	/*u32 flags = pawn->m_fFlags();

	if (!(flags & FL_ONGROUND))
	{
		return;
	}*/
	
	Checkpoint cp = {};
	this->GetOrigin(&cp.origin),
	this->GetAngles(&cp.angles),
	this->GetVelocity(&cp.velocity),

	m_checkpoints.AddToTail(cp);
	// newest checkpoints aren't deleted after using prev cp.
	m_currentCpIndex = m_checkpoints.Count() - 1;
	utils::PrintChat(this->GetPawn(), " \7[SURF] \1Save position \5#%d", m_currentCpIndex + 1);
}

void SURFPlayer::TpToCheckpoint()
{
	if (m_checkpoints.Count() <= 0)
	{
		utils::PrintChat(this->GetPawn(), "No checkpoints available.");
		return;
	}

	const Checkpoint cp = m_checkpoints[m_currentCpIndex];
	this->Teleport(&cp.origin, &cp.angles, &cp.velocity);

	utils::PrintChat(this->GetPawn(), " \7[SURF] x[%.3f] x[%.3f]", cp.angles.x, cp.angles.y);
}

void SURFPlayer::TpToPrevCp()
{
	if (m_checkpoints.Count() <= 0)
	{
		utils::PrintChat(this->GetPawn(), "No checkpoints available.");
		return;
	}
	m_currentCpIndex = MAX(0, m_currentCpIndex - 1);
	const Checkpoint cp = m_checkpoints[m_currentCpIndex];
	this->Teleport(&cp.origin, &cp.angles, &NULL_VECTOR);
}

void SURFPlayer::TpToNextCp()
{
	if (m_checkpoints.Count() <= 0)
	{
		utils::PrintChat(this->GetPawn(), "No checkpoints available.");
		return;
	}
	m_currentCpIndex = MIN(m_currentCpIndex + 1, m_checkpoints.Count() - 1);
	const Checkpoint cp = m_checkpoints[m_currentCpIndex];
	this->Teleport(&cp.origin, &cp.angles, &NULL_VECTOR);
}

void SURFPlayer::OnStartProcessMovement()
{
	MovementPlayer::OnStartProcessMovement();
	this->EnableGodMode();
	this->HandleMoveCollision();
}

void SURFPlayer::OnStopProcessMovement()
{
	SURF::HUD::DrawSpeedPanel(this);
	MovementPlayer::OnStopProcessMovement();
}

void SURFPlayer::ToggleHide()
{
	this->hideOtherPlayers = !this->hideOtherPlayers;
}

void SURFPlayer::ToggleInStrafe()
{
	this->inNoAngle = !this->inNoAngle;
	this->GetAngles(&lastAngles);
	utils::PrintCentre(g_pEntitySystem->GetBaseEntity(CEntityIndex(this->index)), "%s", this->inNoAngle ? "IN STRAFE" : "OUT OF STRAFE");
}

void SURFPlayer::Reset()
{
	MovementPlayer::Reset();

	this->m_currentCpIndex = 0;
	this->hideOtherPlayers = false;
	this->m_checkpoints.Purge();
}