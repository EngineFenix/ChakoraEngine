#include "Camera.h"
#include <stdio.h>

namespace CoreGameplay {
	Camera::Camera() : ProjectionType(PERSPECTIVE), CameraUp(0.0f, 1.0f, 0.0f), CameraLocation(0.0f, 1.0f, 5.0f), CameraCenter(0.0f, 1.0f, -1.0f) { }

	void Camera::SetCameraLocation(float X, float Y, float Z)
	{
		this->CameraLocation.setCoreVector3D(X, Y, Z);
	}

	void Camera::SetCameraCenter(float X, float Y, float Z)
	{
		this->CameraCenter.setCoreVector3D(X, Y, Z);
	}
	
	void Camera::SetCameraUp(float X, float Y, float Z)
	{
		this->CameraUp.setCoreVector3D(X, Y, Z);
	}

	void Camera::SetDeltaAngle(float DeltaAngle)
	{
		this->DeltaAngle = DeltaAngle;
	}

	void Camera::SetDeltaHorizontalMove(float DeltaHorizontalMove)
	{
		this->DeltaHorizontalMove = DeltaHorizontalMove;
	}

	void Camera::SetDeltaVerticalMove(float DeltaVerticalMove)
	{
		this->DeltaVerticalMove = DeltaVerticalMove;
	}

	void Camera::SetXOrigin(int xOrigin)
	{
		this->xOrigin = xOrigin;
	}

	void Camera::SetAngle(float Angle)
	{
		this->Angle = Angle;
	}

	CVector Camera::GetCameraLocation() { return CameraLocation; }
	CVector Camera::GetCameraCenter() { return CameraCenter; }
	CVector Camera::GetCameraUp() { return CameraUp; }
	float Camera::GetDeltaAngle() { return DeltaAngle; }
	float Camera::GetDeltaHorizontalMove() { return DeltaHorizontalMove; }
	float Camera::GetDeltaVerticalMove() { return DeltaVerticalMove; }
	float Camera::GetAngle() { return Angle; }
	int Camera::GetXOrigin() { return xOrigin; }

	void Camera::SetProjectionType(int ProjectionType)
	{
		this->ProjectionType = ProjectionType;
	}

	void Camera::ComputePos(float DeltaHorizontalMoveParam, float DeltaVerticalMoveParam, float Speed) {
		if (DeltaVerticalMoveParam) {
			CameraLocation.x += DeltaVerticalMoveParam * CameraCenter.x * Speed,
			CameraLocation.z += DeltaVerticalMoveParam * CameraCenter.z * Speed;
		} else {
			// Przesuwanie na boki 
			CameraLocation.x += DeltaHorizontalMoveParam * CameraCenter.x * Speed,
			CameraLocation.z += DeltaHorizontalMoveParam * CameraCenter.z * Speed;
		}
	}
}
