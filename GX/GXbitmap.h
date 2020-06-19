#pragma once
#include <GX/GXdebug.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <glad/glad.h>

#include <GX/GXtypedef.h>
#include <GX/GXtexture.h>

GXtexture_t* loadBMPImage(const char path[]); //Loads a BMP file from path and returns a pointer to GXtexture_t
