#include "Scene.h"
#include "../CoreEngine/CoreApp.h"

namespace CoreGameplay {
	Scene::Scene()
	{
		SceneGameMode = new CoreGameplay::GameMode();
		this->SetCamera(SceneGameMode->GetActor()->GetCamera());
	}

	Scene::~Scene()
	{
		delete SceneGameMode;
	}

	void Scene::SetSpawnLocation(float X, float Y, float Z)
	{
		SpawnActor.SpawnLocation.setCoreVector3D(X, Y, Z);
	}

	void Scene::SetSpawnRotation(float Roll, float Pitch, float Yaw)
	{
		SpawnActor.SpawnRotation.setCoreVector3D(Roll, Pitch, Yaw);
	}

	void Scene::SetGameMode(CoreGameplay::GameMode *NewGameMode)
	{
		this->SceneGameMode = NewGameMode;
	}

	void Scene::SetCamera(CoreGameplay::Camera *NewCamera)
	{
		this->SceneCamera = NewCamera;
	}

	CoreGameplay::PlayerStart Scene::GetPlayerStart() { return SpawnActor; }
	CoreGameplay::GameMode * Scene::GetGameMode() { return SceneGameMode; }
	CoreGameplay::Camera * Scene::GetCamera() { return this->SceneCamera; }
}
