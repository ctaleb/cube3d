/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:50:46 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/12 13:05:31 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_minimap(t_mlx_params *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y / mlx->map->ratio < mlx->map->max_y)
	{
		x = 0;
		while (x / mlx->map->ratio < mlx->map->max_x)
		{
			put_map(x, y, mlx);
			x++;
		}
		y++;
	}
}

void	put_map(int x, int y, t_mlx_params *mlx)
{
	if (x / mlx->map->ratio >= mlx->map->max_x
		|| y / mlx->map->ratio >= mlx->map->max_y)
		return ;
	// else if (x % mlx->map->ratio == 0 || y % mlx->map->ratio == 0)
	// 	my_mlx_pixel_put(mlx, x, y, rgbtoi(0, 0, 0, 0));
	else if (mlx->map->grid[y / mlx->map->ratio][x / mlx->map->ratio] == ' ')
		my_mlx_pixel_put(mlx, x, y, rgbtoi(0, 38, 38, 38));
	else if (mlx->map->grid[y / mlx->map->ratio][x / mlx->map->ratio] == '1'
		|| mlx->map->grid[y / mlx->map->ratio][x / mlx->map->ratio] == '3')
		my_mlx_pixel_put(mlx, x, y, rgbtoi(0, 80, 80, 80));
	else if (mlx->map->grid[y / mlx->map->ratio][x / mlx->map->ratio] == '0')
		my_mlx_pixel_put(mlx, x, y, rgbtoi(0, 255, 255, 255));
	else if ((mlx->map->grid[y / mlx->map->ratio][x / mlx->map->ratio] >= '2'
		&& mlx->map->grid[y / mlx->map->ratio][x / mlx->map->ratio] <= '9')
		|| mlx->map->grid[y / mlx->map->ratio][x / mlx->map->ratio] == 'K')
		my_mlx_pixel_put(mlx, x, y, rgbtoi(0, 65, 105, 225));
	else if (mlx->map->grid[y / mlx->map->ratio][x / mlx->map->ratio] == 'N'
		|| mlx->map->grid[y / mlx->map->ratio][x / mlx->map->ratio] == 'S'
		|| mlx->map->grid[y / mlx->map->ratio][x / mlx->map->ratio] == 'E'
		|| mlx->map->grid[y / mlx->map->ratio][x / mlx->map->ratio] == 'W')
		my_mlx_pixel_put(mlx, x, y, rgbtoi(0, 255, 215, 0));
}

void	put_player(t_mlx_params *mlx)
{
	int	x;
	int	y;

	x = mlx->pl->x * mlx->map->ratio;
	y = mlx->pl->y * mlx->map->ratio;
	my_mlx_pixel_put(mlx, x, y, mlx->pl->colour);
	my_mlx_pixel_put(mlx, x - 1, y, mlx->pl->colour);
	my_mlx_pixel_put(mlx, x, y - 1, mlx->pl->colour);
	my_mlx_pixel_put(mlx, x - 1, y - 1, mlx->pl->colour);
}

void	rem_player(t_mlx_params *mlx)
{
	int	x;
	int	y;

	x = mlx->pl->x * mlx->map->ratio;
	y = mlx->pl->y * mlx->map->ratio;
	put_map(x, y, mlx);
	put_map(x - 1, y, mlx);
	put_map(x, y - 1, mlx);
	put_map(x - 1, y - 1, mlx);
}
