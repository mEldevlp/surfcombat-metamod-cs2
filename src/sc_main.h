#pragma once

#include "common.h"


class SurfPlugin : public ISmmPlugin, public IMetamodListener
{
public:
	bool Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late);
	bool Unload(char *error, size_t maxlen);
	bool Pause(char *error, size_t maxlen);
	bool Unpause(char *error, size_t maxlen);
	void AllPluginsLoaded();
	void NextFrame(std::function<void()> fn);
public:
	const char *GetAuthor();
	const char *GetName();
	const char *GetDescription();
	const char *GetURL();
	const char *GetLicense();
	const char *GetVersion();
	const char *GetDate();
	const char *GetLogTag();

	void Hook_ClientCommand(CPlayerSlot slot, const CCommand& args);
	void Hook_GameFrame(bool simulating, bool bFirstTick, bool bLastTick);
	float Hook_ProcessUsercmds_Pre(CPlayerSlot slot, bf_read* buf, int numcmds, bool ignore, bool paused);
	float Hook_ProcessUsercmds_Post(CPlayerSlot slot, bf_read* buf, int numcmds, bool ignore, bool paused);
	void Hook_CEntitySystem_Spawn_Post(int nCount, const EntitySpawnInfo_t* pInfo);
	void Hook_CheckTransmit(CCheckTransmitInfo** pInfo, int, CBitVec<16384>&, const Entity2Networkable_t** pNetworkables, const uint16* pEntityIndicies, int nEntities);
	void Hook_ClientPutInServer(CPlayerSlot slot, char const* pszName, int type, uint64 xuid);

	void Hook_StartupServer(const GameSessionConfiguration_t& config, ISource2WorldSession*, const char*);

	bool Hook_FireGameEvent(IGameEvent* event, bool bDontBroadcast);

private:
	std::deque<std::function<void()>> m_nextFrame;
};

extern SurfPlugin g_SurfPlugin;
