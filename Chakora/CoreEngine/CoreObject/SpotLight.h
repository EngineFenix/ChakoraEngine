#ifndef SPOTLIGHT_H_INCLUDED
#define SPOTLIGHT_H_INCLUDED
#pragma once

#include "../BasicHeaders.h"
#include "..\CoreEngine\Structures.h"
#include "CoreLight.h"

//!  Obiekty przestrzenne
namespace CoreObject {
	class SpotLight : public CoreLight {
	private:
	public:
		SpotLight();
		~SpotLight();
	};
}

#endif