/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:48:07 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/09 16:34:02 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_health(t_mlx_params *mlx, int x, int y)
{
	int	x_max;
	int	y_max;
	int	var_x;

	x_max = x - 5 - 100 + mlx->pl->health;
	y_max = y - 5;
	y -= 20;
	printf("%i\t%i\t%i\n", x_max, x, x - 105);
	while (y < y_max)
	{
		var_x = x - 105;
		while (var_x < x_max)
		{
			my_mlx_pixel_put(mlx, var_x, y, rgbtoi(0, 250, 0, 0));
			var_x++;
		}
		y++;
	}
}

void	put_healthbar(t_mlx_params *mlx)
{
	int	tex_x;
	int	tex_y;
	int	x;
	int	y;

	tex_x = 0;
	tex_y = 0;
	y = (mlx->map->res_y / 4 * 3) - mlx->healthbar->height / 2;
	while (tex_y < mlx->healthbar->height)
	{
		x = mlx->map->res_x / 4 - mlx->healthbar->width / 2;
		tex_x = 0;
		while (tex_x < mlx->healthbar->width)
		{
			my_mlx_pixel_put(mlx, x, y, mlx->healthbar->addr[tex_y * mlx->healthbar->width + tex_x]);
			tex_x++;
			x++;
		}
		tex_y++;
		y++;
	}
	put_health(mlx, x, y);
}
