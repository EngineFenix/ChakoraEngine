#ifndef PLAYERSTART_TIMER_H
#define PLAYERSTART_TIMER_H

#include "../CoreEngine/Structures.h"

namespace CoreGameplay {
	struct PlayerStart
	{
		CVector SpawnLocation;
		CVector SpawnRotation;
		PlayerStart() {
			SpawnLocation.zero();
			SpawnRotation.zero();
		}
	};
}
#endif