/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:36:59 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/30 11:36:59 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argn, char **args)
{
	int	error_code;

	error_code = check_errors(argn, args);
	if (error_code == ERROR)
		return (1);
	else if (error_code == MALLOC_ERROR)
	{
		error_printing("Memory allocation has failed",
			"Make sure you have available RAM.",
			"Try to exit some unused programs.");
		return (1);
	}
	main_game(args[1]);
	return (0);
}
