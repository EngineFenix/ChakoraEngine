#ifndef ATMOSPHERICLIGHT_H_INCLUDED
#define ATMOSPHERICLIGHT_H_INCLUDED
#pragma once

#include "../BasicHeaders.h"
#include "..\CoreEngine\Structures.h"
#include "CoreLight.h"

//!  Obiekty przestrzenne
namespace CoreObject {
	class AtmosphericLight : public CoreLight {
	private:
	public:
		AtmosphericLight();
		~AtmosphericLight();
	};
}

#endif