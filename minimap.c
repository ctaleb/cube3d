/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:50:46 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/25 16:53:06 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_minimap(t_mlx_params *mlx_prms)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y / 10 < mlx_prms->map->max_y)
	{
		x = 0;
		while (x / 10 < mlx_prms->map->max_x && mlx_prms->map->grid[y / 10][x / 10])
		{
			// printf("%c", mlx_prms->map->grid[y][x]);
			if (mlx_prms->map->grid[y / 10][x / 10] == ' ')
				mlx_pixel_put (mlx_prms->ptr, mlx_prms->win, x, y, rgbtoi(0, 38, 38, 38));
			else if (mlx_prms->map->grid[y / 10][x / 10] == '1')
				mlx_pixel_put (mlx_prms->ptr, mlx_prms->win, x, y, rgbtoi(0, 80, 80, 80));
			else if (mlx_prms->map->grid[y / 10][x / 10] == '0')
				mlx_pixel_put (mlx_prms->ptr, mlx_prms->win, x, y, rgbtoi(0, 255, 255, 255));
			else if (mlx_prms->map->grid[y / 10][x / 10] == '2')
				mlx_pixel_put (mlx_prms->ptr, mlx_prms->win, x, y, rgbtoi(0, 65, 105, 225));
			else if (mlx_prms->map->grid[y / 10][x / 10] == 'N' || mlx_prms->map->grid[y / 10][x / 10] == 'S'
						|| mlx_prms->map->grid[y / 10][x / 10] == 'E' || mlx_prms->map->grid[y / 10][x / 10] == 'W')
				mlx_pixel_put (mlx_prms->ptr, mlx_prms->win, x, y, rgbtoi(0, 255, 215, 0));
			x++;
		}
		// printf("\n");
		y++;
	}
}