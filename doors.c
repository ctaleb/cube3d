/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:16:39 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/18 16:44:31 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	linker(t_mlx_params *mlx, int var[2], int vx[2], int vy[2])
{
	vx[1] = vx[0] - var[1];
	while (vx[1] <= vx[0] + var[1])
	{
		if (vx[1] >= 0 && vx[1] < mlx->map->max_x)
		{
			if (mlx->map->grid[vy[1]][vx[1]] == '7'
				|| mlx->map->grid[vy[1]][vx[1]] == '8')
			{
				if (mlx->map->grid[vy[1]][vx[1]] == '7')
					mlx->sp[var[0]]->state = 0;
				else
					mlx->sp[var[0]]->state = 1;
				mlx->sp[var[0]]->door_x = vx[1];
				mlx->sp[var[0]]->door_y = vy[1];
				return (1);
			}
		}
		if (vy[1] == vy[0] - var[1] || vy[1] == vy[0] + var[1])
			vx[1]++;
		else
			vx[1] += 2 * var[1];
	}
	return (0);
}

void	link_door(t_mlx_params *mlx, int i, int x, int y)
{
	int	var[2];
	int	vx[2];
	int	vy[2];

	var[0] = i;
	var[1] = 1;
	vx[0] = x;
	vy[0] = y;
	while (!mlx->sp[i]->door_x && !mlx->sp[i]->door_y)
	{
		vy[1] = vy[0] - var[1];
		while (vy[1] <= vy[0] + var[1])
		{
			if (vy[1] >= 0 && vy[1] < mlx->map->max_y)
			{
				if (linker(mlx, var, vx, vy))
					return ;
			}
			vy[1]++;
		}
		var[1]++;
	}
}
