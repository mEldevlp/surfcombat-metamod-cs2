#pragma once

#include "cbaseplayercontroller.h"
#include "services.h"

class CCSPlayerController : public CBasePlayerController
{
public:
	DECLARE_SCHEMA_CLASS(CCSPlayerController);
	SCHEMA_FIELD(CCSPlayerController_ActionTrackingServices*, m_pActionTrackingServices)
	SCHEMA_FIELD(int, m_iScore)
	SCHEMA_FIELD(int, m_iMVPs)
	SCHEMA_FIELD(bool, m_bPawnIsAlive);
};