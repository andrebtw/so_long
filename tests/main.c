#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct s_map
{
    int    y;
    int    x;
}    t_map;

int path[8][5] = {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1}, 
    {1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};


int    main(void)
{
    t_map map;
    t_map end;

    map.y = 1;
    map.x = 3;
    end.y = 6;
    end.x = 3;
    int f = findpath(map, end);
	printf("%d", f);
    return (0);
}
