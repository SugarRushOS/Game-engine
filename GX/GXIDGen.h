#pragma once
#include <GX/GXdebug.h>

#include <GX/GXtypedef.h>

inline GXsize_t GXIDGen()
{
	static GXsize_t ret = 0;
	return ret++;
}