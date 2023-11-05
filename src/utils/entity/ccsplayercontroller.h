#pragma once

#include "cbaseplayercontroller.h"
#include "services.h"

class CCSPlayerController : public CBasePlayerController
{
public:
	DECLARE_SCHEMA_CLASS(CCSPlayerController);
	SCHEMA_FIELD(bool, m_bPawnIsAlive);
};