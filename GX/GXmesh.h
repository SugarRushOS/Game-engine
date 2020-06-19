#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <glad/glad.h>

#include <GX/GXdebug.h>

#include <GX/GXtypedef.h>
#include <GX/GXdimension.h>

#include <GX/GXchecksum.h>
#include <GX/GXIDGen.h>

struct faces_s
{
	int3_t* v;
	int3_t* vt;
	int3_t* vn;
};
typedef struct faces_s faces_t;

struct GXMesh_s
{
	GXsize_t ID;
	faces_t faces;

	GXsize_t  geometricVerticesCount;
	GXsize_t  textureCoordinatesCount;
	GXsize_t  vertexNormalsCount;
	GXsize_t  facesCount;

	//Array
	GLuint vertexArray;
	//geometric vertecies
	GLuint vertexBuffer;
	GLuint elementBuffer;
	//textures
	GLuint textureBuffer;
};
typedef struct GXMesh_s GXmesh_t;

int unloadMesh(GXmesh_t* mesh); //Destroy a mesh and all of its contents