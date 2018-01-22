#ifndef TGA_H_INCLUDED
#define TGA_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "../BasicHeaders.h"
#include "../CoreEngine\Structures.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

typedef struct {
	GLuint bpp;		// iloœæ bitów na piksel
	GLuint width;	// rozmiary w pikselach
	GLuint height;
} TARGAINFO;

namespace CoreTexture {
	class TGA
	{
	public:
		TGA();
		~TGA();
		GLubyte * LoadTGAImage(std::string filename, TARGAINFO *info);
		bool LoadTGATexture(std::string filename);
		bool LoadTGAMipmap(std::string filename);
	};
};

#endif

