#pragma once
#include <GX/GXdebug.h>

#include <GX/GXtypedef.h>
#include <GX/GXmesh.h>
#include <GX/GXtexture.h>
#include <GX/GXshader.h>
#include <GX/GXIDGen.h>

#define GXE_present  0x00000001
#define GXE_mesh     0x00000002
#define GXE_shader   0x00000004
#define GXE_texture  0x00000008
#define GXE_drawable 0x00000010
#define GXE_

#define GXE_PMSTD GXE_present | GXE_mesh | GXE_shader | GXE_texture | GXE_drawable

struct GXEntity_s
{
	GXsize_t           ID;
	GXsize_t           flags;
	char*              name;
	GXmesh_t*          mesh;
	GXshader_t*        shader;
	GXtexture_t*       UV;
	struct GXEntity_s* next;
};
typedef struct GXEntity_s GXentity_t;

GXentity_t* createEntity(GXsize_t flags);                            // Creates an entity, assigns flags, and returns pointer to it
int         drawEntity(GXentity_t* entity);                          // Draws an entity if draw flag == 1
GXentity_t* loadEntity(const char path[]);
int         assignTexture(GXentity_t* entity, const char uniform[]); // Assigns a texture to a glsl uniform
int         destroyEntity(GXentity_t* entity);                       // Destroys the entity and all its contents