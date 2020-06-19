#pragma once

#include <GX/GXshader.h>

GXshader_t* loadShader(const char vertexShaderPath[], const char fragmentShaderPath[])
{
	//Uninitialized data
	char* vfdata,* ffdata;
	int vfi, ffi;
	unsigned int vShader, fShader;

	//Initialized data
	FILE* vf = fopen(vertexShaderPath, "r");
	FILE* ff = fopen(fragmentShaderPath, "r");
	
	GXshader_t* ret = malloc(sizeof(GXshader_t));

	//Find file size and prep for read
	fseek(vf, 0, SEEK_END);
	fseek(ff, 0, SEEK_END);

	vfi = ftell(vf);
	ffi = ftell(ff);

	fseek(vf, 0, SEEK_SET);
	fseek(ff, 0, SEEK_SET);

	//Allocate data and read file into memory
	vfdata = malloc(vfi);
	ffdata = malloc(ffi);
	
	fread(vfdata, 1, vfi, vf);
	fread(ffdata, 1, ffi, ff);

	//We no longer need the file
	fclose(vf);
	fclose(ff);

	//Compile, attach, and link shaders
	vShader = glCreateShader(GL_VERTEX_SHADER);
	fShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vShader, 1, &vfdata, NULL);
	glShaderSource(fShader, 1, &ffdata, NULL);

	glCompileShader(vShader);
	glCompileShader(fShader);

	ret->shaderProgramID = glCreateProgram();

	glAttachShader(ret->shaderProgramID, vShader);
	glAttachShader(ret->shaderProgramID, fShader);

	glLinkProgram(ret->shaderProgramID);

	//Destroy the shader programs we don't need anymore
	glDeleteShader(vShader);
	glDeleteShader(fShader);

	//We no longer need the shader text
	free(vfdata);
	free(ffdata);

	return ret;

}

int useShader(GXshader_t* shader)
{
	glUseProgram(shader->shaderProgramID);
	return 0;
}

void setShaderInt(GXshader_t* shader, const char name[], int value)
{

}

void setShaderFloat(GXshader_t* shader, const char name[], float value)
{

}

int unloadShader(GXshader_t* shader)
{
	//Deallocate associated data
	glDeleteProgram(shader->shaderProgramID);
	free(shader);

	return 0;
}