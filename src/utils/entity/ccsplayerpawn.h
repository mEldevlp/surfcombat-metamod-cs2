#pragma once

#include "cbaseplayerpawn.h"

class CCSPlayer_ActionTrackingServices;

class CCSPlayerPawnBase : public CBasePlayerPawn
{
public:
	DECLARE_SCHEMA_CLASS(CCSPlayerPawnBase);
	SCHEMA_FIELD(float, m_flSlopeDropOffset)
	SCHEMA_FIELD(float, m_flSlopeDropHeight)
	SCHEMA_FIELD(CCSPlayer_ActionTrackingServices*, m_pActionTrackingServices)
};

class CCSPlayerPawn : public CCSPlayerPawnBase
{
public:
	DECLARE_SCHEMA_CLASS(CCSPlayerPawn);
};