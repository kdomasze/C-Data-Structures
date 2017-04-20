#ifndef MAP_H
#define MAP_H

struct Map_t;

typedef struct Map_t
{
	int *data;
	int _size;
} Map;

/*
 * initializes a new map
 */
Map* kd_map_new(int size);

/*
 * frees a map from memory
 */
void kd_map_free(Map* map);

/*
 * inserts a (key, value) pair into the specified map.
 * currently collisions will overwrite previous inserts
 * with no recovery
 */
void kd_map_insert(Map* map, char* key, int value);

/*
 *returns a value from the given key in the the specified
 * map
 */
int kd_map_get(Map* map, char* key);

/*
 * generates a valid index from the hashed key supplied
 * for a given map
 */
int _kd_map_hash_key(Map* map, unsigned long hash);

/*
 * generates a hash of the given key using the djb2
 * algorithm
 */
unsigned long _kd_map_hash(char* key);

#endif
