#include <GX/GXscene.h>

GXscene_t* createScene()
{
	GXscene_t* ret = malloc(sizeof(GXscene_t));
	ret->sceneID = GXIDGen();
	ret->head = 0;
	return ret;
}

GXscene_t* loadScene(const char path[])
{
	//Uninitialized data
	int i;
	char* data;

	//Initialized data
	GXscene_t* ret = malloc(sizeof(GXscene_t));

	//Open file for reading
	FILE* f = fopen(path, "r");

	//Find file size and prep for read
	fseek(f, 0, SEEK_END);
	i = ftell(f);
	fseek(f, 0, SEEK_SET);

	//Allocate data and read file into memory
	data = malloc(i);
	fread(data, 1, i, f);

	//We no longer need the file
	fclose(f);

	while (*data)
	{
		if(*data == '{')
		{
		
		}
		if(*data == '}')
		{
		
		}
		if(*data == '[')
		{
		
		}
		if(*data == ']')
		{
		
		}
		if(*data == '\"')
		{
			data++;
			if (strncmp(data, "scene", strlen("scene")) == 0)
				printf("found a scene!\n");
			if (strncmp(data, "SceneName", strlen("SceneName")) == 0)
			{
				while (*data++ != '\"');
				while (*data++ != '\"');
				while (*data != '\"')
					putchar(*data++);
			}
			if (strncmp(data, "entity", strlen("entity")) == 0)
			{

			}
		}
		

		data++;
	}

	return ret;
}

int appendEntity(GXscene_t* scene, GXentity_t* entity)
{

	GXentity_t* i = scene->head;
	//Check if the head is null
	if (i == 0)
	{
		scene->head = entity;
		return 0;
	}
	//Search for the end of the LL
	while (i->next)
		i = i->next;

	//Assign next as entity
	i->next = entity;

	return 0;
}

int drawScene(GXscene_t* scene)
{
	GXentity_t* i = scene->head;
	if (i == 0)
		return -1;
	while (i)
	{
		drawEntity(i);
		i = i->next;
	}

	return 0;
}

GXentity_t* getEntity(GXscene_t* scene, const char name[])
{
	GXentity_t* i = scene->head;
	if (i == 0)
		return (void*)0;
	while (i)
	{
		if (strcmp(name, i->name) == 0)
			return i;
		i = i->next;
	}
	return (void*) 0;
}

int removeEntity(GXscene_t* scene, const char name[])
{

	GXentity_t* i = scene->head;
	if (i == 0)
		return -1;
	while (i->next)
	{
		if (strcmp(name, i->next->name) == 0) 
		{
			//TODO: Handle edge cases
			GXentity_t* j = i->next->next;
			destroyEntity(i->next);
			#ifdef debugmode
				printf("Destroyed entity %s", name);
			#endif
			i->next = j;
			return 0;
		}
		i = i->next;
	}
	return 0;
}

int destroyScene(GXscene_t* scene)
{
	scene->sceneID = 0;
	GXentity_t* i = scene->head;
	while (i)
	{
		GXentity_t* j = i;
		i = i->next;
		destroyEntity(j);
	}
	return 0;
}