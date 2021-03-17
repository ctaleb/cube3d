/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:52:50 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/17 12:27:29 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	movement(t_mlx_params *mlx)
{
	float speed;

	if ((mlx->input->forward || mlx->input->backward)
		&& (mlx->input->strafe_l || mlx->input->strafe_r))
		speed = 0.025;
	else
		speed = 0.050;
	if (mlx->input->forward && !mlx->input->backward)
		move_pl(13, mlx, speed);
	else if (mlx->input->backward && !mlx->input->forward)
		move_pl(1, mlx, speed);
	if (mlx->input->strafe_l && !mlx->input->strafe_r)
		strafe_pl(0, mlx, speed);
	else if (mlx->input->strafe_r && !mlx->input->strafe_l)
		strafe_pl(2, mlx, speed);
	if (mlx->input->rotate_l && !mlx->input->rotate_r)
		rotate_pl(123, mlx, speed);
	else if (mlx->input->rotate_r && !mlx->input->rotate_l)
		rotate_pl(124, mlx, speed);
	sprite_dist(mlx);
	return (0);

	// sprite_reset(mlx);
	// if (keycode == 126 || keycode == 13 || keycode == 125 || keycode == 1)
	// 	move_pl(keycode, mlx);
	// else if (keycode == 123 || keycode == 124)
	// 	rotate_pl(keycode, mlx);
	// else if (keycode == 0 || keycode == 2)
	// 	strafe_pl(keycode, mlx);
}

int	move_pl(int keycode, t_mlx_params *mlx, float speed)
{
	if (keycode == 126 || keycode == 13)
	{
		if (check_coords('F', mlx, speed))
		{
			mlx->pl->x = mlx->pl->x + mlx->f->cam_x * speed;
			mlx->pl->y = mlx->pl->y + mlx->f->cam_y * speed;
		}
	}
	else if (keycode == 125 || keycode == 1)
	{
		if (check_coords('B', mlx, speed))
		{
			mlx->pl->x = mlx->pl->x - mlx->f->cam_x * speed;
			mlx->pl->y = mlx->pl->y - mlx->f->cam_y * speed;
		}
	}
	return (0);
}

int	rotate_pl(int keycode, t_mlx_params *mlx, float speed)
{
	float	vec_x;
	float	vec_y;

	vec_x = mlx->f->cam_x;
	vec_y = mlx->f->cam_y;
	if (keycode == 123)
	{
		mlx->f->cam_x = vec_x * cos(-speed) - vec_y * sin(-speed);
		mlx->f->cam_y = vec_x * sin(-speed) + vec_y * cos(-speed);
	}
	else if (keycode == 124)
	{
		mlx->f->cam_x = vec_x * cos(speed) - vec_y * sin(speed);
		mlx->f->cam_y = vec_x * sin(speed) + vec_y * cos(speed);
	}
	return (0);
}

int	strafe_pl(int keycode, t_mlx_params *mlx, float speed)
{
	float	vec_x;
	float	vec_y;

	vec_x = mlx->f->cam_x;
	vec_y = mlx->f->cam_y;
	mlx->f->cam_x = vec_x * cos(-1.5708) - vec_y * sin(-1.5708);
	mlx->f->cam_y = vec_x * sin(-1.5708) + vec_y * cos(-1.5708);
	if (keycode == 0)
	{
		if (check_coords('F', mlx, speed))
		{
			mlx->pl->x = mlx->pl->x + mlx->f->cam_x * speed;
			mlx->pl->y = mlx->pl->y + mlx->f->cam_y * speed;
		}
	}
	else if (keycode == 2)
	{
		if (check_coords('B', mlx, speed))
		{
			mlx->pl->x = mlx->pl->x - mlx->f->cam_x * speed;
			mlx->pl->y = mlx->pl->y - mlx->f->cam_y * speed;
		}
	}
	mlx->f->cam_x = vec_x;
	mlx->f->cam_y = vec_y;
	return (0);
}

int	check_coords(char dir, t_mlx_params *mlx, float speed)
{
	wall_dist_calc(dir, mlx);
	if (dir == 'F')
	{
		mlx->pl->f_x = mlx->pl->x + mlx->f->cam_x * speed;
		mlx->pl->f_y = mlx->pl->y + mlx->f->cam_y * speed;
		if (!wall_check(mlx->pl->f_x, mlx->pl->f_y, mlx))
			return (0);
		return (1);
	}
	else if (dir == 'B')
	{
		mlx->pl->f_x = mlx->pl->x - mlx->f->cam_x * speed;
		mlx->pl->f_y = mlx->pl->y - mlx->f->cam_y * speed;
		inverse_cam('B', mlx);
		if (!wall_check(mlx->pl->f_x, mlx->pl->f_y, mlx))
		{
			inverse_cam('B', mlx);
			return (0);
		}
		inverse_cam('B', mlx);
		return (1);
	}
	return (1);
}
