#ifndef POINTLIGHT_H_INCLUDED
#define POINTLIGHT_H_INCLUDED
#pragma once

#include "../BasicHeaders.h"
#include "..\CoreEngine\Structures.h"
#include "CoreLight.h"

//!  Obiekty przestrzenne
namespace CoreObject {
	class PointLight : public CoreLight {
	private:
	public:
		PointLight();
		~PointLight();
	};
}

#endif