/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:52:50 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/25 11:07:50 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	movement(int keycode, t_mlx_params *mlx)
{
	// rem_camera(mlx);
	// rem_player(mlx);
	if (keycode == 126 || keycode == 13 || keycode == 125 || keycode == 1)
		move_pl(keycode, mlx);
	else if (keycode == 0 || keycode == 2)
		rotate_pl(keycode, mlx);
	return (0);
}

int	move_pl(int keycode, t_mlx_params *mlx)
{
	if (keycode == 126 || keycode == 13)
	{
		if (check_coords('F', mlx))
		{
			mlx->pl->x = mlx->pl->x + mlx->f->cam_x * 0.1;
			mlx->pl->y = mlx->pl->y + mlx->f->cam_y * 0.1;
		}
	}
	else if (keycode == 125 || keycode == 1)
	{
		if (check_coords('B', mlx))
		{
			mlx->pl->x = mlx->pl->x - mlx->f->cam_x * 0.1;
			mlx->pl->y = mlx->pl->y - mlx->f->cam_y * 0.1;
		}
	}
	return (0);
}

int	rotate_pl(int keycode, t_mlx_params *mlx)
{
	float	vec_x;
	float	vec_y;

	// rem_camera(mlx);
	// rem_player(mlx);
	vec_x = mlx->f->cam_x;
	vec_y = mlx->f->cam_y;
	if (keycode == 0)
	{
		mlx->f->cam_x = vec_x * cos(-0.1) - vec_y * sin(-0.1);
		mlx->f->cam_y = vec_x * sin(-0.1) + vec_y * cos(-0.1);
	}
	else if (keycode == 2)
	{
		mlx->f->cam_x = vec_x * cos(0.1) - vec_y * sin(0.1);
		mlx->f->cam_y = vec_x * sin(0.1) + vec_y * cos(0.1);
	}
	return (0);
}

int	check_coords(char dir, t_mlx_params *mlx)
{
	float	x;
	float	y;

	dist_calc(dir, mlx);
	//printf("\nwx%f\twy%f\ncx%f\tcy%f\n", mlx->pl->nwall_x, mlx->pl->nwall_y, mlx->pl->x, mlx->pl->y);
	if (dir == 'F')
	{
		x = mlx->pl->x + mlx->f->cam_x * 0.1;
		y = mlx->pl->y + mlx->f->cam_y * 0.1;
		// printf("x%f\ty%f\n", x, y);
		if (!wall_check(x, y, mlx))
			return (0);
		return (1);
	}
	else if (dir == 'B')
	{
		x = mlx->pl->x - mlx->f->cam_x * 0.1;
		y = mlx->pl->y - mlx->f->cam_y * 0.1;
		inverse_cam('B', mlx);
		if (!wall_check(x, y, mlx))
		{
			inverse_cam('B', mlx);	
			return (0);
		}
		inverse_cam('B', mlx);
		return (1);
	}
	return (1);
}
