/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:42:04 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/26 13:46:04 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	player_down(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y + 1][mlx->player.x])) &&
		!mlx->collectibles_n)
		mlx->player.end = 1;
	if (ft_strchr("0PC", (mlx->map[mlx->player.y + 1][mlx->player.x])))
	{
		mlx->player.y = mlx->player.y + 1;
		if (mlx->map[mlx->player.y][mlx->player.x] == 'C')
			mlx->collectibles_n--;
		ft_printf("Movement count : %d\n", mlx->mouvement_count + 1);
		return (re_render(mlx, -1, 0));
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}

int	player_left(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y][mlx->player.x - 1])) &&
		!mlx->collectibles_n)
			mlx->player.end = 1;
	if (ft_strchr("0PC", (mlx->map[mlx->player.y][mlx->player.x - 1])))
	{
		mlx->player.x = mlx->player.x - 1;
		if (mlx->map[mlx->player.y][mlx->player.x] == 'C')
			mlx->collectibles_n--;
		ft_printf("Movement count : %d\n", mlx->mouvement_count + 1);
		return (re_render(mlx, 0, 1));
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}

int	player_right(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y][mlx->player.x + 1])) &&
		!mlx->collectibles_n)
		mlx->player.end = 1;
	if (ft_strchr("0PC", mlx->map[mlx->player.y][mlx->player.x + 1]))
	{
		mlx->player.x = mlx->player.x + 1;
		if (mlx->map[mlx->player.y][mlx->player.x] == 'C')
			mlx->collectibles_n--;
		ft_printf("Movement count : %d\n", mlx->mouvement_count + 1);
		return (re_render(mlx, 0, -1));
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}

int	player_up(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y - 1][mlx->player.x])) &&
		!mlx->collectibles_n)
		mlx->player.end = 1;
	if (ft_strchr("0PC", (mlx->map[mlx->player.y - 1][mlx->player.x])))
	{
		mlx->player.y = mlx->player.y - 1;
		if (mlx->map[mlx->player.y][mlx->player.x] == 'C')
			mlx->collectibles_n--;
		ft_printf("Movement count : %d\n", mlx->mouvement_count + 1);
		return (re_render(mlx, 1, 0));
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}
