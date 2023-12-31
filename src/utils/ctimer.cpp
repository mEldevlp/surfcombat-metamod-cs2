#include "ctimer.h"

CUtlLinkedList<CTimerBase*> g_timers;

void RemoveTimers()
{
	g_timers.PurgeAndDeleteElements();
}

void RemoveMapTimers()
{
    for (int i = g_timers.Tail(); i != g_timers.InvalidIndex();)
    {
        int prevIndex = i;
        i = g_timers.Previous(i);

        if(g_timers[prevIndex]->m_bPreserveMapChange)
            continue;

        ConMsg("remove timer\n");

        delete g_timers[prevIndex];
        g_timers.Remove(prevIndex);
    }
}