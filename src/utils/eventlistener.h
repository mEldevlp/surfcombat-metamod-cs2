#pragma once

#include "common.h"
#include "utlstring.h"
#include "utlvector.h"
#include "utils.h"

#define CEL_PROCEED_EVENT_HANDLING 0x2A

typedef void (*FnEventListenerCallback)(IGameEvent* event);

class CGameEventListener;
extern CUtlVector<CGameEventListener*> g_vecEventListeners;

class CGameEventListener : public IGameEventListener2
{
public:
	CGameEventListener(FnEventListenerCallback callback, const char* pszEventName) : m_Callback(callback), m_pszEventName(pszEventName)
	{
		g_vecEventListeners.AddToTail(this);
	}

	~CGameEventListener() override
	{
	}

	void FireGameEvent(IGameEvent* pEvent)
	{
		utils::ClientPrintAll(MsgDest::HUD_PRINTTALK, " \5[EVENT] id- \7%d", pEvent->GetID());
		m_Callback(pEvent);
	}

	const char* GetEventName() { return m_pszEventName; }

private:
	FnEventListenerCallback m_Callback;
	const char* m_pszEventName;
};

void RegisterEventListeners();
void UnregisterEventListeners();

extern IServerGameClients* g_pSource2GameClients;
extern CEntitySystem* g_pEntitySystem;
extern CGlobalVars* gpGlobals;
extern IGameEventManager2* g_gameEventManager;

#define GAME_EVENT_F(_event)												\
	void _event##_callback(IGameEvent*);									\
	CGameEventListener _event##_listener(_event##_callback, #_event);		\
	void _event##_callback(IGameEvent *pEvent)