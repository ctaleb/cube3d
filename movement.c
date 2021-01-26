/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:52:50 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/26 16:26:21 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		move_pl(int keycode, t_mlx_params *mlx)
{
	rem_player(mlx);
	if (keycode == 126 || keycode == 13)
	{
		if (check_coords(mlx->pl->x, mlx->pl->y - 0.1, mlx->map))
			mlx->pl->y -= 0.1;
	}
	else if (keycode == 123 || keycode == 12)
	{
		if (check_coords(mlx->pl->x - 0.1, mlx->pl->y, mlx->map))
			mlx->pl->x -= 0.1;
	}
	else if (keycode == 125 || keycode == 1)
	{
		if (check_coords(mlx->pl->x, mlx->pl->y + 0.1, mlx->map))
			mlx->pl->y += 0.1;
	}
	else if (keycode == 124 || keycode == 14)
	{
		if (check_coords(mlx->pl->x + 0.1, mlx->pl->y, mlx->map))
			mlx->pl->x += 0.1;
	}
	put_player(mlx);
	return (0);
}

int		rotate_pl(int keycode, t_mlx_params *mlx)
{
	float	vec_x;
	float	vec_y;

	vec_x = mlx->pl->cam_x;
	vec_y = mlx->pl->cam_y;
	rem_camera(mlx);
	if (keycode == 0)
	{
		mlx->pl->cam_x = vec_x * cos(0.1) - vec_y * sin(0.1);
		mlx->pl->cam_y = vec_x * sin(0.1) + vec_y * cos(0.1);
	}
	else if (keycode == 2)
	{
		mlx->pl->cam_x = vec_x * cos(-0.1) - vec_y * sin(-0.1);
		mlx->pl->cam_y = vec_x * sin(-0.1) + vec_y * cos(-0.1);
	}
	put_camera(mlx);
	return (0);
}

int		check_coords(float x, float y, t_map *map)
{
	if (x - 0.1 < 0 || y - 0.1 < 0)
		return (0);
	else if (x > map->max_x || y > map->max_y)
		return (0);
	else if (map->grid[(int)y][(int)x] == '1')
		return (0);
	else if (map->grid[(int)(y - 0.1)][(int)(x - 0.1)] == '1')
		return (0);
	return (1);
}