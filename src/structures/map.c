#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "map.h"

Map* kd_map_new(int size)
{
	int* data = (int*)(malloc(sizeof(int) * size));
	Map* map = (Map*)(malloc(sizeof(Map)));
	(*map).data = data;
	(*map)._size = size;

	return map;
}

void kd_map_free(Map* map)
{
	free((*map).data);
	free(map);
}

void kd_map_insert(Map* map, char* key, int value)
{
	unsigned long hash = _kd_map_hash(key);
	int hashed_key = _kd_map_hash_key(map, hash);

	(*map).data[hashed_key] = value;
}

int kd_map_get(Map* map, char* key)
{
	unsigned long hash = _kd_map_hash(key);
	int hashed_key = _kd_map_hash_key(map, hash);
	
	return (*map).data[hashed_key];
}

int _kd_map_hash_key(Map* map, unsigned long hash)
{
	float rand = 1; /*0.618033;*/

	return (int)((unsigned long)(rand * hash) % (unsigned long)(*map)._size);
}

unsigned long _kd_map_hash(char* key)
{
	int i;
	unsigned long hashed_key = 5381;

	for(i = 0; key[i] != '\0'; i++)
	{
		hashed_key = ((hashed_key << 5) + hashed_key) + key[i]; 
	}

	return hashed_key;
}
