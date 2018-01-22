#include "GameMode.h"

namespace CoreGameplay {
	GameMode::GameMode()
	{
		PlayerController = new CoreInput::InputController();
		PlayerActor = new CoreGameplay::Actor();
	}

	GameMode::~GameMode()
	{
		delete PlayerController;
		delete PlayerActor;
	}

	CoreInput::InputController * GameMode::GetController() { return PlayerController; }

	CoreGameplay::Actor * GameMode::GetActor() { return PlayerActor; }
}
