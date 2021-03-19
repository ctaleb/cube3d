/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:52:50 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/19 16:52:41 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	movement(t_mlx_params *mlx)
{
	float	speed;

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
	if (keycode == 123)
		ft_vec_rot(&mlx->f->cam_x, &mlx->f->cam_y, -speed);
	else if (keycode == 124)
		ft_vec_rot(&mlx->f->cam_x, &mlx->f->cam_y, speed);
	return (0);
}

int	strafe_pl(int keycode, t_mlx_params *mlx, float speed)
{
	ft_vec_rot(&mlx->f->cam_x, &mlx->f->cam_y, deg_rad(-90));
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
	ft_vec_rot(&mlx->f->cam_x, &mlx->f->cam_y, deg_rad(90));
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
