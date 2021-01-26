/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:50:46 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/26 15:04:06 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_minimap(t_mlx_params *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y / 10 < mlx->map->max_y)
	{
		x = 0;
		while (x / 10 < mlx->map->max_x /*&& mlx->map->grid[y / 10][x / 10]*/)
		{
			put_map(x, y, mlx);
			x++;
		}
		y++;
	}
}

void	put_map(int x, int y, t_mlx_params *mlx)
{
	if (mlx->map->grid[y / 10][x / 10] == ' ')
		mlx_pixel_put(mlx->ptr, mlx->win, x, y, rgbtoi(0, 38, 38, 38));
	else if (mlx->map->grid[y / 10][x / 10] == '1')
		mlx_pixel_put(mlx->ptr, mlx->win, x, y, rgbtoi(0, 80, 80, 80));
	else if (mlx->map->grid[y / 10][x / 10] == '0')
		mlx_pixel_put(mlx->ptr, mlx->win, x, y, rgbtoi(0, 255, 255, 255));
	else if (mlx->map->grid[y / 10][x / 10] == '2')
		mlx_pixel_put(mlx->ptr, mlx->win, x, y, rgbtoi(0, 65, 105, 225));
	else if (mlx->map->grid[y / 10][x / 10] == 'N'
			|| mlx->map->grid[y / 10][x / 10] == 'S'
			|| mlx->map->grid[y / 10][x / 10] == 'E'
			|| mlx->map->grid[y / 10][x / 10] == 'W')
	mlx_pixel_put(mlx->ptr, mlx->win, x, y, rgbtoi(0, 255, 215, 0));
}

void	put_player(t_mlx_params *mlx)
{
	int x;
	int y;
	
	x = mlx->pl->x * 10;
	y = mlx->pl->y * 10;
	mlx_pixel_put(mlx->ptr, mlx->win, x, y, mlx->pl->colour);
	mlx_pixel_put(mlx->ptr, mlx->win, x - 1, y, mlx->pl->colour);
	mlx_pixel_put(mlx->ptr, mlx->win, x, y - 1, mlx->pl->colour);
	mlx_pixel_put(mlx->ptr, mlx->win, x - 1, y - 1, mlx->pl->colour);
}

void	rem_player(t_mlx_params *mlx)
{
	int x;
	int y;

	x = mlx->pl->x * 10;
	y = mlx->pl->y * 10;
	put_map(x, y, mlx);
	put_map(x - 1, y, mlx);
	put_map(x, y - 1, mlx);
	put_map(x - 1, y - 1, mlx);
}