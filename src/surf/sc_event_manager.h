#include "sc_main.h"
#include "utils/utils.h"

class Event;

extern std::unordered_map<EventID, Event*> g_umpEventManager;
extern std::queue<std::function<void()>> g_qEventsInit;

class Event
{
public:
	Event() = delete;
	Event(const Event& e) = delete;

	Event(std::function<bool(IGameEvent*)> callback, std::function<void()> init)
	{
		g_qEventsInit.push(init);
		m_fnCallback = callback;
	}

	~Event()
	{
	}

	void CallBack(IGameEvent* pEvent)
	{
		this->m_fnCallback(pEvent);
	}

private:
	std::function<bool(IGameEvent*)> m_fnCallback = nullptr;
};

void Init_EventManager();

#define GAME_EVENT(_eventname, _eventid)															\
	bool _eventname##_callback(IGameEvent*);														\
	void _eventname##_init();																		\
	Event* _eventname##_inst = new Event(_eventname##_callback, _eventname##_init);					\
	void _eventname##_init()																		\
	{																								\
		g_umpEventManager.insert({(_eventid), (_eventname##_inst)});								\
	}																								\
	bool _eventname##_callback(IGameEvent* pEvent)													