/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:52:50 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/24 13:36:19 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	move(t_mlx_params *mlx, float speed)
{
	if (mlx->input->forward && !mlx->input->backward)
		move_pl(13, mlx, speed);
	else if (mlx->input->backward && !mlx->input->forward)
		move_pl(1, mlx, speed);
	if (mlx->input->strafe_l && !mlx->input->strafe_r)
		strafe_pl(0, mlx, speed);
	else if (mlx->input->strafe_r && !mlx->input->strafe_l)
		strafe_pl(2, mlx, speed);
	if (mlx->input->rotate_l && !mlx->input->rotate_r)
		rotate_pl(123, mlx, speed * 1.5);
	else if (mlx->input->rotate_r && !mlx->input->rotate_l)
		rotate_pl(124, mlx, speed * 1.5);
	if (mlx->input->mouse_x < mlx->map->res_x / 2)
		rotate_pl(123, mlx, speed);
	else if (mlx->input->mouse_x > mlx->map->res_x / 2)
		rotate_pl(124, mlx, speed);
}

int	movement(t_mlx_params *mlx)
{
	float	speed;

	if ((mlx->input->forward || mlx->input->backward)
		&& (mlx->input->strafe_l || mlx->input->strafe_r))
		speed = 0.025;
	else
		speed = 0.050;
	if (mlx->input->crouch)
		speed = 0.02;
	move(mlx, speed);
	relocate(mlx);
	sprite_dist(mlx);
	return (0);
}

int	move_pl(int keycode, t_mlx_params *mlx, float speed)
{
	if (keycode == 126 || keycode == 13)
	{
		if (check_f_coords('x', mlx, speed))
			mlx->pl->x = mlx->pl->x + mlx->f->cam_x * speed;
		if (check_f_coords('y', mlx, speed))
			mlx->pl->y = mlx->pl->y + mlx->f->cam_y * speed;
	}
	else if (keycode == 125 || keycode == 1)
	{
		if (check_b_coords('x', mlx, speed))
			mlx->pl->x = mlx->pl->x - mlx->f->cam_x * speed;
		if (check_b_coords('y', mlx, speed))
			mlx->pl->y = mlx->pl->y - mlx->f->cam_y * speed;
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
		if (check_f_coords('x', mlx, speed))
			mlx->pl->x = mlx->pl->x + mlx->f->cam_x * speed;
		if (check_f_coords('y', mlx, speed))
			mlx->pl->y = mlx->pl->y + mlx->f->cam_y * speed;
	}
	else if (keycode == 2)
	{
		if (check_b_coords('x', mlx, speed))
			mlx->pl->x = mlx->pl->x - mlx->f->cam_x * speed;
		if (check_b_coords('y', mlx, speed))
			mlx->pl->y = mlx->pl->y - mlx->f->cam_y * speed;
	}
	ft_vec_rot(&mlx->f->cam_x, &mlx->f->cam_y, deg_rad(90));
	return (0);
}
