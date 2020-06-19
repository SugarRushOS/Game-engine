#pragma once

#include <GX/GXentity.h>

GXentity_t* createEntity(GXsize_t flags)
{
	GXentity_t* ret = malloc(sizeof(GXentity_t));
	//ID
	ret->ID     = GXIDGen();
	//Set flags
	ret->flags  = flags;
	//Initialize to nullptr
	ret->mesh   = (void*)0;
	ret->name   = (void*)0;
	ret->next   = (void*)0;
	ret->shader = (void*)0;
	ret->UV     = (void*)0;
	return ret;
}

int drawEntity(GXentity_t* entity)
{
	//Check if its drawable
	if (!(entity->flags & GXE_drawable))
		return -1;
	//Check if we have a texture and if we are permitted to use it
	if (entity->UV && entity->flags & GXE_texture) {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, entity->UV->textureID);
	}
	//Draw the entity
	useShader(entity->shader);
	glBindVertexArray(entity->mesh->vertexArray);
	glDrawElements(GL_TRIANGLES, entity->mesh->facesCount * 3, GL_UNSIGNED_INT, 0);

	return 0;
}

int assignTexture(GXentity_t* entity, const char uniform[])
{
	useShader(entity->shader);
	glUniform1i(glGetUniformLocation(entity->shader->shaderProgramID, uniform), 0);
	return 0;
}

int destroyEntity(GXentity_t* entity)
{
	entity->ID = 0;

	if (entity->name != (void*)0)
		entity->name = (void*)0;

	if (entity->mesh != (void*)0)
		unloadMesh(entity->mesh);

	if (entity->shader != (void*)0)
		unloadShader(entity->shader);

	if (entity->UV != (void*)0)
		unloadTexture(entity->UV);
	
	free(entity);

	return 0;
}
