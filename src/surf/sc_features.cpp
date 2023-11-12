#include "sc_features.h"

SpawnProtection g_SpawnProtection;

void SpawnProtection::SetSpawnColor(int r, int g, int b)
{	
	if (r > 255 || r < 0) return;
	if (g > 255 || g < 0) return;
	if (b > 255 || b < 0) return;

	this->m_clrPlayerSpawn.SetColor(r, g, b, 255);
}

Color SpawnProtection::GetSpawnColor() const
{
	return this->m_clrPlayerSpawn;
}

void SpawnProtection::SetTimeProtection(float time)
{
	if (time > 255.0f || time < 0.0f) return;

	this->m_iTimeProtection = time;
}

float SpawnProtection::GetTimeProtection() const
{
	return this->m_iTimeProtection;
}

void SpawnProtection::Init_SpawnProtection()
{
	this->m_iTimeProtection = 10.0f;
	this->m_clrPlayerSpawn = Color(255, 255, 0, 255);
}