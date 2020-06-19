#pragma once
#include <GX/GXdebug.h>

#include <GX/GXtypedef.h>

typedef u8 GXchecksum_t;

GXchecksum_t checksum(void* ptr, GXsize_t size); //Generates 8 bit checksum
