#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#pragma once

#include "../CoreGameplay/PlayerStart.h"
#include "../CoreGameplay/GameMode.h"
#include "../CoreGameplay/Camera.h"
#include "../CoreEngine/Structures.h"

namespace CoreGameplay {
	class Scene
	{
	private:
		CoreGameplay::PlayerStart SpawnActor;
		CoreGameplay::GameMode * SceneGameMode;
		CoreGameplay::Camera * SceneCamera;
	public:
		Scene();
		~Scene();
		void SetSpawnLocation(float X, float Y, float Z);
		void SetSpawnRotation(float Roll, float Pitch, float Yaw);
		void SetGameMode(CoreGameplay::GameMode *NewGameMode);
		void SetCamera(CoreGameplay::Camera *NewCamera);
		CoreGameplay::PlayerStart GetPlayerStart();
		CoreGameplay::GameMode * GetGameMode();
		CoreGameplay::Camera * GetCamera();
	};
}

#endif
