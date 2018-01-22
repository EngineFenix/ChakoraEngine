#include "Actor.h"

namespace CoreGameplay {
	Actor::Actor() : MoveSpeed(0.2)
	{
		this->ActorCamera = new CoreGameplay::Camera();
	}

	Actor::~Actor()
	{
	}

	void Actor::SetCamera(CoreGameplay::Camera *NewCamera)
	{
		this->ActorCamera = NewCamera;
	}
	CoreGameplay::Camera * Actor::GetCamera()
	{
		return this->ActorCamera;
	}
	float Actor::GetMoveSpeed()
	{
		return this->MoveSpeed;
	}
	void Actor::SetMoveSpeed(float Speed) {
		this->MoveSpeed = Speed;
	}
}