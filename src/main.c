#include "header.h"

int	main(int argn, char **args)
{
	int	error_code;

	error_code = check_errors(argn, args);
	if (error_code == ERROR)
		return (1);
	else if (error_code == MALLOC_ERROR)
	{
		error_printing("Memory allocation has failed", "Make sure you have available RAM.", "Try to exit some unused programs.");
		return (1);
	}
	main_game(args[1]);
	return (0);
}
