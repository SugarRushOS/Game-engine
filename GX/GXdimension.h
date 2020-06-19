#pragma once
#include <GX/GXdebug.h>

struct point2_s {
	float u;
	float v;
};
typedef struct point2_s point2_t;

struct point3_s {
	float x;
	float y;
	float z;
};
typedef struct point3_s point3_t;

struct point4_s {
	float s;
	float i;
	float j;
	float k;
};
typedef struct point4_s point4_t;

struct int3_s {
	int x;
	int y;
	int z;
};
typedef struct int3_s int3_t;