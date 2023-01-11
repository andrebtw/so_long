#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int path[8][5] = {
    {1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1}, 
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};

typedef struct s_map
{
    int    y;
    int    x;
}    t_map;

