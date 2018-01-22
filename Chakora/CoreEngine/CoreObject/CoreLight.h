#ifndef CORELIGHT_H_INCLUDED
#define CORELIGHT_H_INCLUDED
#pragma once

#include "../BasicHeaders.h"
#include "..\CoreEngine\Structures.h"

//!  Obiekty przestrzenne
namespace CoreObject {
	class CoreLight {
	private:
	public:
		CVector		ObjectLocation; /*!< Wektor po�o�enia */
		CVector		ObjectRotation; /*!< Wektor obroty */
		CVector		ObjectResize; /*!< Wektor skalowania */
		CColor		LightColor; /*!< Kolor emitowanego �wiat�a */
		float		Intensity; /*!< Jasno�� */
		float		LightmapResolution; /*!< Promie� rozproszenia cienia */ 

		/** \todo Stworzy� shader, s�u��cy do rozpraszania cieni o promieniu ustalonym przez zmienn� LightmapResolution. */

		CoreLight(CVector Location, float Intensity, CColor Color);
		~CoreLight();
		void SetLocation(CVector Location);
		void SetRotation(CVector Rotation);
		void SetScale(CVector Scale);
		void SetColor(CColor Color);
		void SetIntensity(float Intensity);
	};
}

#endif