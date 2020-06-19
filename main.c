#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include <glad/glad.h>

#include <GX/GXtypedef.h>

#include <GX/GXentity.h>

#include <GX/GXmesh.h>
#include <GX/GXobj.h>

#include <GX/GXshader.h>

#include <GX/GXtexture.h>
#include <GX/GXbitmap.h>

#include <GX/GXchecksum.h>
#include <GX/GXIDGen.h>

#include <GX/GXscene.h>

#undef main

int main(int argc, const char* argv[])
{
	//Uninitialized data
	SDL_Window*   window;
	SDL_Event     event;
	SDL_GLContext glContext;

	//Initialized Data

	//SDL + GLAD Initialization Junk
	{
		if (SDL_Init(SDL_INIT_EVERYTHING))
		{
			printf("Failed to initialize SDL\n");
			return -1;
		}

		window = SDL_CreateWindow("GX",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			720,
			720,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

		glContext = SDL_GL_CreateContext(window);

		if (!window)
		{
			printf("Failed to create a window\n");
			return -1;
		}
		if (!glContext)
		{
			printf("Failed to create an OpenGL Context\n");
			return -1;
		}
		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
			printf("Failed to load OpenGL");
			return -1;
		}
	}
	/*
	//GX Initialization Junk
	{
		//Earth 0
		{
			GXtexture_t* earthuv;
			GXmesh_t* earthmesh;
			GXshader_t* earthshader;

			earth0      = createEntity(GXE_PMSTD);
			earthmesh   = loadOBJMesh("gameassets/models/earth0.obj");
			earthuv     = loadBMPImage("gameassets/textures/earthuv0.bmp");
			earthshader = loadShader("gameassets/shaders/earth.glvs", "gameassets/shaders/earth.glfs");

			earth0->name   = "earth0";
			earth0->ID     = GXIDGen();
			earth0->mesh   = earthmesh;
			earth0->UV     = earthuv;
			earth0->shader = earthshader;

			assignTexture(earth0, "txsamp");
		}
		//Earth 1
		{
			GXtexture_t* earthuv;
			GXmesh_t* earthmesh;
			GXshader_t* earthshader;

			earth1      = createEntity(GXE_PMSTD);
			earthmesh   = loadOBJMesh("gameassets/models/earth1.obj");
			earthuv     = loadBMPImage("gameassets/textures/earthuv1.bmp");
			earthshader = loadShader("gameassets/shaders/earth.glvs", "gameassets/shaders/earth.glfs");
			
			earth1->name   = "earth1";
			earth1->ID     = GXIDGen();
			earth1->mesh   = earthmesh;
			earth1->UV     = earthuv;
			earth1->shader = earthshader;

			assignTexture(earth1, "txsamp");
		}
		//Earth 2
		{
			GXtexture_t* earthuv;
			GXmesh_t* earthmesh;
			GXshader_t* earthshader;

			earth2      = createEntity(GXE_PMSTD);
			earthmesh   = loadOBJMesh("gameassets/models/earth2.obj");
			earthuv     = loadBMPImage("gameassets/textures/earthuv2.bmp");
			earthshader = loadShader("gameassets/shaders/earth.glvs", "gameassets/shaders/earth.glfs");

			earth2->name   = "earth2";
			earth2->ID     = GXIDGen();
			earth2->mesh   = earthmesh;
			earth2->UV     = earthuv;
			earth2->shader = earthshader;

			assignTexture(earth2, "txsamp");
		}
		//Earth 3
		{
			GXtexture_t* earthuv;
			GXmesh_t* earthmesh;
			GXshader_t* earthshader;

			earth3      = createEntity(GXE_PMSTD);
			earthmesh   = loadOBJMesh("gameassets/models/earth3.obj");
			earthuv     = loadBMPImage("gameassets/textures/earthuv3.bmp");
			earthshader = loadShader("gameassets/shaders/earth.glvs", "gameassets/shaders/earth.glfs");

			earth3->name   = "earth3";
			earth3->ID     = GXIDGen();
			earth3->mesh   = earthmesh;
			earth3->UV     = earthuv;
			earth3->shader = earthshader;

			assignTexture(earth3, "txsamp");
		}
	}
	
	appendEntity(scene, earth0);
	appendEntity(scene, earth1);
	appendEntity(scene, earth2);
	appendEntity(scene, earth3);
	*/
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	u8 running = 1;
	GXentity_t* e;
	while (running)
	{
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
				case SDL_QUIT:
					running = 0;
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
						case SDLK_ESCAPE:
							running = 0;
							break;
						default:
							break;
					}
			}
		}

		glClearColor(0.f,0.f, 0.f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//drawScene(scene);

		SDL_GL_SwapWindow(window);
	}

	//SDL Deinitialization
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	//GX Unloading;
	{
		//destroyScene(scene);
	}
	return 0;
}