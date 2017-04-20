#include <stdio.h>
#include "../structures/map.h"

void test_map()
{
	int test_values[7] = {10, 20, 30, 40, 50, 60, 70};

	char* test_keys[7] = {"Hello", "Good", "a", "olleH", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "!@#$%^&*()", "a space"};

	Map* map = kd_map_new(21);

	int i;
	for(i = 0; i < 7; i++)
	{
		printf("Key: %s, Value: %d\n", test_keys[i], test_values[i]);
		kd_map_insert(map, test_keys[i], test_values[i]);
	}
	
	for(i = 0; i < 7; i++)
	{
		if(kd_map_get(map, test_keys[i]) == test_values[i])
		{
			printf("%d == %d\n", kd_map_get(map, test_keys[i]), test_values[i]);
		}
		else
		{
			printf("%d != %d\n", kd_map_get(map, test_keys[i]), test_values[i]);
		}
	}

	kd_map_free(map);	
}
