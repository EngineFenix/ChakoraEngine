#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED
#pragma once
 
#include "../BasicHeaders.h"
#include "..\CoreEngine\Structures.h"
#include "..\CoreEngine\BasicVariables.h"

//!  Rozgrywka
namespace CoreGameplay {
	//!  Kamera 3D. 
	/*!
	Klasa fizycznej kamery w przestrzeni 3D
	*/
	class Camera
	{
	private:
		CVector CameraLocation;
		CVector CameraCenter;
		CVector CameraUp;
		int ProjectionType;
		float Angle = 0.0f;
		float DeltaAngle = 0.0f;
		float DeltaVerticalMove = 0.0f;
		float DeltaHorizontalMove = 0.0f;
		int xOrigin = -1;
	public:
		Camera();
		~Camera();
		void SetCameraLocation(float X, float Y, float Z);
		void SetCameraCenter(float X, float Y, float Z);
		void SetCameraUp(float X, float Y, float Z);
		void SetDeltaAngle(float DeltaAngle);
		void SetDeltaHorizontalMove(float DeltaHorizontalMove);
		void SetDeltaVerticalMove(float DeltaVerticalMove);
		void SetXOrigin(int xOrigin);
		void SetAngle(float Angle);
		float GetDeltaVerticalMove();
		float GetDeltaHorizontalMove();
		float GetDeltaAngle();
		int GetXOrigin();
		float GetAngle();
		CVector GetCameraLocation();
		CVector GetCameraCenter();
		CVector GetCameraUp();
		void ComputePos(float DeltaHorizontalMoveParam, float DeltaVerticalMoveParam, float Speed);
		void SetProjectionType(int ProjectionType);
	};
}

#endif