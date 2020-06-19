#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <glad/glad.h>

#include <GX/GXdebug.h>

#include <GX/GXtypedef.h>

struct GXtexture_s
{
	unsigned int textureID;
	GXsize_t width;
	GXsize_t height;
	u8* pixelData;
};
typedef struct GXtexture_s GXtexture_t;

int unloadTexture(GXtexture_t* image); //Unloads a texture and all of its contents

