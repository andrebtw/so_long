#include "../header.h"

int	check_errors(int argn, char **args)
{
	if (argn == 1)
	{
		error_printing("No Arguments.", "Make sure to add a .ber map format", "./so_long map.ber");
		return (-1);
	}
	if (argn != 2)
	{
		error_printing("More than one argument.", "Make sure to only add your .ber map", "./so_long map.ber");
		return (-1);
	}
	if (!args)
		return (-1);
	return (0);	
}
