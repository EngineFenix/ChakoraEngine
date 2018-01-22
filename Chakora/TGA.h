#ifndef TGA_H_INCLUDED
#define TGA_H_INCLUDED
#pragma once

#include "../BasicHeaders.h"
#include "CoreEngine\Structures.h"

namespace CoreTexture {
	class TGA
	{
	public:
		TGA::TGA();
		TGA::~TGA();
		GLubyte * LoadTGAImage(char *filename, TARGAINFO *info);
		bool LoadTGATexture(char *filename);
		bool LoadTGAMipmap(char *filename);
	};
};

#endif

