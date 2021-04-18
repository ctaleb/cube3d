/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:24:10 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/18 17:27:40 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	door_opener(t_mlx_params *mlx, int i)
{
	int	d_x;
	int	d_y;

	d_x = mlx->sp[i]->door_x;
	d_y = mlx->sp[i]->door_y;
	if (mlx->map->grid[d_y][d_x] == '8')
	{
		mlx->map->grid[d_y][d_x] = '7';
		mlx->sp[i]->state = 0;
	}
	else
	{
		mlx->map->grid[d_y][d_x] = '8';
		mlx->sp[i]->state = 1;
	}
	mlx->input->action = 0;
}
