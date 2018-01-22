#ifndef GAMEMODE_H_INCLUDED
#define GAMEMODE_H_INCLUDED

#pragma once

#include "../BasicHeaders.h"
#include "../CoreInput/InputController.h"
#include "../CoreGameplay/Actor.h"

namespace CoreGameplay {
	class GameMode
	{
	private:
		CoreInput::InputController * PlayerController;
		CoreGameplay::Actor * PlayerActor;
	public:
		GameMode();
		~GameMode();
		CoreInput::InputController * GetController();
		CoreGameplay::Actor * GetActor();
		int a;
	};
}

#endif