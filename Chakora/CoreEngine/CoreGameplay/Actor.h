#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

#pragma once

#include "../BasicHeaders.h"
#include "Camera.h"
#include "../CoreObject/MeshArea.h"

namespace CoreGameplay {
	class Actor
	{
	private:
		float MoveSpeed;
		CoreGameplay::Camera * ActorCamera;
		CoreObject::MeshArea * ActorMeshArea;
	public:
		Actor();
		~Actor();
		void SetCamera(CoreGameplay::Camera *NewCamera);
		CoreGameplay::Camera * GetCamera();
		void SetMoveSpeed(float Speed);
		float GetMoveSpeed();
	};
}

#endif