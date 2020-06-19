#pragma once

#include <GX/GXtexture.h>

int unloadTexture(GXtexture_t* image)
{
	//Free pixel data and invalidate width, height, and pixeldata pointer. Free image.
	free(image->pixelData);
	image->pixelData = (void*)0;
	image->width = 0;
	image->height = 0;
	glDeleteTextures(1, &image->textureID);
	free(image);
	return 0;
}