#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <GX/GXdebug.h>

#include <GX/GXtypedef.h>
#include <GX/GXmesh.h>

#include <GX/GXchecksum.h>
#include <GX/GXIDGen.h>

GXmesh_t* loadOBJMesh(const char path[]); //Loads an OBJ file from path and returns a pointer to GXmesh_t
