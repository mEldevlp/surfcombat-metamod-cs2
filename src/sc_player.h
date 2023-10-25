#pragma once
#include "precompiled.h"

class SurfPlayer
{
public:
	SurfPlayer(int i) : index(i) {}

	CCSPlayerController* GetController();
	CCSPlayerPawn* GetPawn();
	CPlayerSlot GetPlayerSlot() { return index - 1; };

	void Teleport(const Vector* origin, const QAngle* angles, const Vector* velocity);
	void GetOrigin(Vector* origin);
	void SetOrigin(const Vector& origin);

	void GetVelocity(Vector* velocity);
	void SetVelocity(const Vector& velocity);

	void GetAngles(QAngle* angles);
	void SetAngles(const QAngle& angles);

public:
	const i32 index;
};