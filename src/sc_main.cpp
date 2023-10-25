#include <stdio.h>
#include "sc_main.h"
#include "iserver.h"

SH_DECL_HOOK3_void(IServerGameDLL, GameFrame, SH_NOATTRIB, 0, bool, bool, bool);
SH_DECL_HOOK4_void(IServerGameClients, ClientActive, SH_NOATTRIB, 0, CPlayerSlot, bool, const char *, uint64);
SH_DECL_HOOK5_void(IServerGameClients, ClientDisconnect, SH_NOATTRIB, 0, CPlayerSlot, int, const char *, uint64, const char *);
SH_DECL_HOOK4_void(IServerGameClients, ClientPutInServer, SH_NOATTRIB, 0, CPlayerSlot, char const *, int, uint64);
SH_DECL_HOOK1_void(IServerGameClients, ClientSettingsChanged, SH_NOATTRIB, 0, CPlayerSlot );
SH_DECL_HOOK6_void(IServerGameClients, OnClientConnected, SH_NOATTRIB, 0, CPlayerSlot, const char*, uint64, const char *, const char *, bool);
SH_DECL_HOOK6(IServerGameClients, ClientConnect, SH_NOATTRIB, 0, bool, CPlayerSlot, const char*, uint64, const char *, bool, CBufferString *);
SH_DECL_HOOK2(IGameEventManager2, FireEvent, SH_NOATTRIB, 0, bool, IGameEvent *, bool);

SH_DECL_HOOK2_void( IServerGameClients, ClientCommand, SH_NOATTRIB, 0, CPlayerSlot, const CCommand & );

SCPlugin g_SCPlugin;
IServerGameDLL *server = NULL;
IServerGameClients *gameclients = NULL;
IVEngineServer *engine = NULL;
IGameEventManager2 *gameevents = NULL;
ICvar *icvar = NULL;

// Should only be called within the active game loop (i e map should be loaded and active)
// otherwise that'll be nullptr!
CGlobalVars *GetGameGlobals()
{
	INetworkGameServer *server = g_pNetworkServerService->GetIGameServer();

	if(!server)
		return nullptr;

	return g_pNetworkServerService->GetIGameServer()->GetGlobals();
}

#if 0
// Currently unavailable, requires hl2sdk work!
ConVar sample_cvar("sample_cvar", "42", 0);
#endif

CON_COMMAND_F(sample_command, "Sample command", FCVAR_NONE)
{
	META_CONPRINTF( "Sample command called by %d. Command: %s\n", context.GetPlayerSlot(), args.GetCommandString() );
}

PLUGIN_EXPOSE(SCPlugin, g_SCPlugin);
bool SCPlugin::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	PLUGIN_SAVEVARS();

	GET_V_IFACE_CURRENT(GetEngineFactory, engine, IVEngineServer, INTERFACEVERSION_VENGINESERVER);
	GET_V_IFACE_CURRENT(GetEngineFactory, icvar, ICvar, CVAR_INTERFACE_VERSION);
	GET_V_IFACE_ANY(GetServerFactory, server, IServerGameDLL, INTERFACEVERSION_SERVERGAMEDLL);
	GET_V_IFACE_ANY(GetServerFactory, gameclients, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
	GET_V_IFACE_ANY(GetEngineFactory, g_pNetworkServerService, INetworkServerService, NETWORKSERVERSERVICE_INTERFACE_VERSION);

	// Currently doesn't work from within mm side, use GetGameGlobals() in the mean time instead
	// gpGlobals = ismm->GetCGlobals();

	META_CONPRINTF( "Starting plugin.\n" );

	SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &SCPlugin::Hook_GameFrame, true);
	SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientActive, gameclients, this, &SCPlugin::Hook_ClientActive, true);
	SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &SCPlugin::Hook_ClientDisconnect, true);
	SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientPutInServer, gameclients, this, &SCPlugin::Hook_ClientPutInServer, true);
	SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientSettingsChanged, gameclients, this, &SCPlugin::Hook_ClientSettingsChanged, false);
	SH_ADD_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &SCPlugin::Hook_OnClientConnected, false);
	SH_ADD_HOOK_MEMFUNC( IServerGameClients, ClientConnect, gameclients, this, &SCPlugin::Hook_ClientConnect, false );
	SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &SCPlugin::Hook_ClientCommand, false);

	META_CONPRINTF( "All hooks started!\n" );

	g_pCVar = icvar;
	ConVar_Register( FCVAR_RELEASE | FCVAR_CLIENT_CAN_EXECUTE | FCVAR_GAMEDLL );

	return true;
}

bool SCPlugin::Unload(char *error, size_t maxlen)
{
	SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &SCPlugin::Hook_GameFrame, true);
	SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientActive, gameclients, this, &SCPlugin::Hook_ClientActive, true);
	SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &SCPlugin::Hook_ClientDisconnect, true);
	SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientPutInServer, gameclients, this, &SCPlugin::Hook_ClientPutInServer, true);
	SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientSettingsChanged, gameclients, this, &SCPlugin::Hook_ClientSettingsChanged, false);
	SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &SCPlugin::Hook_OnClientConnected, false);
	SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &SCPlugin::Hook_ClientConnect, false);
	SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &SCPlugin::Hook_ClientCommand, false);

	return true;
}

void SCPlugin::AllPluginsLoaded()
{
	/* This is where we'd do stuff that relies on the mod or other plugins 
	 * being initialized (for example, cvars added and events registered).
	 */
}

void SCPlugin::Hook_ClientActive( CPlayerSlot slot, bool bLoadGame, const char *pszName, uint64 xuid )
{
	META_CONPRINTF( "Hook_ClientActive(%d, %d, \"%s\", %d)\n", slot, bLoadGame, pszName, xuid );
}

void SCPlugin::Hook_ClientCommand( CPlayerSlot slot, const CCommand &args )
{
	META_CONPRINTF( "Hook_ClientCommand(%d, \"%s\")\n", slot, args.GetCommandString() );
}

void SCPlugin::Hook_ClientSettingsChanged( CPlayerSlot slot )
{
	META_CONPRINTF( "Hook_ClientSettingsChanged(%d)\n", slot );
}

void SCPlugin::Hook_OnClientConnected( CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, const char *pszAddress, bool bFakePlayer )
{
	META_CONPRINTF( "Hook_OnClientConnected(%d, \"%s\", %d, \"%s\", \"%s\", %d)\n", slot, pszName, xuid, pszNetworkID, pszAddress, bFakePlayer );
}

bool SCPlugin::Hook_ClientConnect( CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, bool unk1, CBufferString *pRejectReason )
{
	META_CONPRINTF( "Hook_ClientConnect(%d, \"%s\", %d, \"%s\", %d, \"%s\")\n", slot, pszName, xuid, pszNetworkID, unk1, pRejectReason->ToGrowable()->Get() );

	RETURN_META_VALUE(MRES_IGNORED, true);
}

void SCPlugin::Hook_ClientPutInServer( CPlayerSlot slot, char const *pszName, int type, uint64 xuid )
{
	META_CONPRINTF( "Hook_ClientPutInServer(%d, \"%s\", %d, %d, %d)\n", slot, pszName, type, xuid );
}

void SCPlugin::Hook_ClientDisconnect( CPlayerSlot slot, int reason, const char *pszName, uint64 xuid, const char *pszNetworkID )
{
	META_CONPRINTF( "Hook_ClientDisconnect(%d, %d, \"%s\", %d, \"%s\")\n", slot, reason, pszName, xuid, pszNetworkID );
}

void SCPlugin::Hook_GameFrame( bool simulating, bool bFirstTick, bool bLastTick )
{
	/**
	 * simulating:
	 * ***********
	 * true  | game is ticking
	 * false | game is not ticking
	 */
}

// Potentially might not work
void SCPlugin::OnLevelInit( char const *pMapName,
									 char const *pMapEntities,
									 char const *pOldLevel,
									 char const *pLandmarkName,
									 bool loadGame,
									 bool background )
{
	META_CONPRINTF("OnLevelInit(%s)\n", pMapName);
}

// Potentially might not work
void SCPlugin::OnLevelShutdown()
{
	META_CONPRINTF("OnLevelShutdown()\n");
}

bool SCPlugin::Pause(char *error, size_t maxlen)
{
	return true;
}

bool SCPlugin::Unpause(char *error, size_t maxlen)
{
	return true;
}

const char *SCPlugin::GetLicense()
{
	return "MIT License";
}

const char *SCPlugin::GetVersion()
{
	return "0.1-a";
}

const char *SCPlugin::GetDate()
{
	return __DATE__;
}

const char *SCPlugin::GetLogTag()
{
	return "Surf";
}

const char *SCPlugin::GetAuthor()
{
	return "\\mEl\\";
}

const char *SCPlugin::GetDescription()
{
	return "Surf Combat for CS2";
}

const char *SCPlugin::GetName()
{
	return "SurfCombat";
}

const char *SCPlugin::GetURL()
{
	return "http://www.sourcemm.net/";
}
