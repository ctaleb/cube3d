/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:52:50 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/05 14:17:03 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	movement(int keycode, t_mlx_params *mlx)
{
	if (keycode == 126 || keycode == 13 || keycode == 125 || keycode == 1)
		move_pl(keycode, mlx);
	else if (keycode == 0 || keycode == 2)
		rotate_pl(keycode, mlx);
	return (0);
}

int	move_pl(int keycode, t_mlx_params *mlx)
{
	rem_player(mlx);
	rem_camera(mlx);
	if (keycode == 126 || keycode == 13)
	{
		if (check_coords('F', mlx))
		{
			mlx->pl->x = mlx->pl->x + mlx->pl->cam_x * 0.1;
			mlx->pl->y = mlx->pl->y + mlx->pl->cam_y * 0.1;
		}
	}
	else if (keycode == 125 || keycode == 1)
	{
		if (check_coords('B', mlx))
		{
			mlx->pl->x = mlx->pl->x - mlx->pl->cam_x * 0.1;
			mlx->pl->y = mlx->pl->y - mlx->pl->cam_y * 0.1;
		}
	}
	put_player(mlx);
	put_camera(mlx);
	return (0);
}

int	rotate_pl(int keycode, t_mlx_params *mlx)
{
	float	vec_x;
	float	vec_y;

	vec_x = mlx->pl->cam_x;
	vec_y = mlx->pl->cam_y;
	rem_camera(mlx);
	if (keycode == 0)
	{
		mlx->pl->cam_x = vec_x * cos(-0.1) - vec_y * sin(-0.1);
		mlx->pl->cam_y = vec_x * sin(-0.1) + vec_y * cos(-0.1);
	}
	else if (keycode == 2)
	{
		mlx->pl->cam_x = vec_x * cos(0.1) - vec_y * sin(0.1);
		mlx->pl->cam_y = vec_x * sin(0.1) + vec_y * cos(0.1);
	}
	put_camera(mlx);
	return (0);
}

int	check_coords(char dir, t_mlx_params *mlx)
{
	float	x;
	float	y;

	dist_calc(mlx);
	printf("\nwx%f\twy%f\n", mlx->pl->nwall_x, mlx->pl->nwall_y);
	if (dir == 'F')
	{
		x = mlx->pl->x + mlx->pl->cam_x * 0.1;
		y = mlx->pl->y + mlx->pl->cam_y * 0.1;
		printf("x%f\ty%f\n", x, y);
		if (!wall_check(x, y, mlx))
			return (0);
		return (1);
	}
	else if (dir == 'B')
	{
		x = mlx->pl->x - mlx->pl->cam_x * 0.1;
		y = mlx->pl->y - mlx->pl->cam_y * 0.1;
		if (!wall_check(x, y, mlx))
			return (0);
		// if (x > mlx->pl->nwall_x || y > mlx->pl->nwall_y)
		// {
			// mlx->pl->y = nearbyint((int)y);
			// mlx->pl->x = nearbyint((int)x);
			// if (fabsf(y - (int)y) != 0)
			// 	mlx->pl->y = mlx->pl->y + (fabsf(y - (int)y));
			// if (fabsf(x - (int)x) != 0)
			// 	mlx->pl->x = mlx->pl->x - (fabsf(x - (int)x));
		// 	return (0);
		// }
		return (1);
	}
	return (1);
}
