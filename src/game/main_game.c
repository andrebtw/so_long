#include "../header.h"

int	main_game(char *file)
{
	char	**map;

	map = map_opening(file);
	if (!map)
		return (ERROR);
	ft_printf(map[0]);
	return (0);
}
