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
		CVector		ObjectLocation; /*!< Wektor po³o¿enia */
		CVector		ObjectRotation; /*!< Wektor obroty */
		CVector		ObjectResize; /*!< Wektor skalowania */
		CColor		LightColor; /*!< Kolor emitowanego œwiat³a */
		float		Intensity; /*!< Jasnoœæ */
		float		LightmapResolution; /*!< Promieñ rozproszenia cienia */ 

		/** \todo Stworzyæ shader, s³u¿¹cy do rozpraszania cieni o promieniu ustalonym przez zmienn¹ LightmapResolution. */

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