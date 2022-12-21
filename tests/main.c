#include <stdio.h>
#include <stdlib.h>

char file[6][10] = {
	"1111111111", 
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1111111111", 
};

typedef struct s_map
{
	int	y;
	int	x;
}	t_map;

int	findpath(int y, int x, t_map map)
{
	if (map.y == y && map.x == x)
	{
		file[y][x] = '*';
		return (1);
	}
	if (file[y][x] == '0' || file[y][x] == '*')
	{
		if (file[y][x + 1] == '0' || file[y][x + 1] == '*')
		{
			file[y][x + 1] = '*';
			return (findpath(y, x+1, map));
		}
		if (file[y + 1][x] == '0' || file[y + 1][x] == '*')
		{
			file[y + 1][x] = '*';
			return (findpath(y + 1, x, map));
		}
		return (0);
	}
	return (0);
}

int	main(void)
{
	t_map map;

	map.x = 2;
	map.y = 4;
	int x = 1;
	int y = 1;
	int i = 0;
	int j = 0;
	//findpath(y, x, map);
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			printf("%c", file[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
