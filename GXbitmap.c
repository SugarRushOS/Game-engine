#pragma once

#include <GX/GXbitmap.h>

GXtexture_t* loadBMPImage(const char path[])
{
	//Uninitialized data
	int i;

	//Initialized data
	GXtexture_t* ret = malloc(sizeof(GXtexture_t));
	FILE* f = fopen(path, "rb");

	if (f == NULL)
	{
		printf("Failed to load file %s\n", path);
		return (void*)0;
	}

	//Find file size and prep for read
	fseek(f, 0, SEEK_END);
	i = ftell(f);
	fseek(f, 0, SEEK_SET);

	//Allocate data and read file into memory
	u8* data = malloc(i);
	fread(data, 1, i, f);

	//We no longer need the file
	fclose(f);

	//Fill out width and height information
	ret->width = *(GXsize_t*)&data[0x12];
	ret->height = *(GXsize_t*)&data[0x16];

	//Allocate space for pixel data
	ret->pixelData = malloc(*(GXsize_t*)&data[0x22]);

	#ifdef debugmode
	printf("Loaded file %s\nWidth  %i\nHeight %i\n\n",path, ret->width, ret->height);
	#endif 
	/*
	
	Loaded file gameassets/models/earth2.obj


Totals:
Geometric vertices   482
Texture coordinates  559
Vertex normals       552
Faces                960
*/

	glGenTextures(1, &ret->textureID);
	glBindTexture(GL_TEXTURE_2D, ret->textureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ret->width, ret->height, 0, GL_BGR, GL_UNSIGNED_BYTE, &data[0x36]);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glGenerateMipmap(GL_TEXTURE_2D);

	//Free data. We don't really need the header anymore. 
	free(data);

	return ret;
}