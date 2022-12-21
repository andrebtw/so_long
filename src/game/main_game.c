/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:38:55 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/21 17:12:25 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/*int	graphics_init(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}*/
//graphics_init();
int	main_game(char *file)
{
	char	**map;

	map = map_opening(file);
	if (!map)
		return (ERROR);
	if (map_check(map, file) == ERROR)
		return (tab_free(map), ERROR);
	return (tab_free(map), 0);
}
