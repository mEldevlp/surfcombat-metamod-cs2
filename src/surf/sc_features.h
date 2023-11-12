#include "sc_main.h"
#include "utils/utils.h"
#include "utils/ctimer.h"

class SpawnProtection
{
public:
	void SetSpawnColor(int r, int g, int b);
	Color GetSpawnColor() const;
	void SetTimeProtection(float time);
	float GetTimeProtection() const;

	void Init_SpawnProtection();
private:
	Color m_clrPlayerSpawn;
	float m_iTimeProtection;
};

extern SpawnProtection g_SpawnProtection;