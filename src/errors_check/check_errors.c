#include "../header.h"

int	check_errors(int argn, char **args)
{
	if (argn == 1)
	{
		error_printing("No Arguments.", "Make sure to add a .ber map format", "./so_long map.ber");
		return (ERROR);
	}
	if (argn != 2)
	{
		error_printing("More than one argument.", "Make sure to only add your .ber map", "./so_long map.ber");
		return (ERROR);
	}
	if (ft_strnstr(args[1], ".ber", __LONG_LONG_MAX__) == NULL)
	{
		error_printing("Invalid map format.", "Make sure that the map is a .ber format", "./so_long map.ber");
		return (ERROR);
	}
	return (0);	
}
