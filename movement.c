/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:52:50 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/05 15:42:23 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	relocate(t_mlx_params *mlx)
{
	if (mlx->map->grid[(int)mlx->pl->y][(int)mlx->pl->x + 1] == '1'
		&& mlx->pl->x > (int)mlx->pl->x + 0.9)
		mlx->pl->x = (int)mlx->pl->x + 0.9;
	else if (mlx->map->grid[(int)mlx->pl->y][(int)mlx->pl->x - 1] == '1'
		&& mlx->pl->x < (int)mlx->pl->x + 0.1)
		mlx->pl->x = (int)mlx->pl->x + 0.1;
	if (mlx->map->grid[(int)mlx->pl->y + 1][(int)mlx->pl->x] == '1'
		&& mlx->pl->y > (int)mlx->pl->y + 0.9)
		mlx->pl->y = (int)mlx->pl->y + 0.9;
	else if (mlx->map->grid[(int)mlx->pl->y - 1][(int)mlx->pl->x] == '1'
		&& mlx->pl->y < (int)mlx->pl->y + 0.1)
		mlx->pl->y = (int)mlx->pl->y + 0.1;
	if (!mlx->save)
		mlx_mouse_move(mlx->win, mlx->map->res_x / 2, mlx->map->res_y / 2);
	mlx->input->mouse_x = mlx->map->res_x / 2;
	mlx->input->mouse_y = mlx->map->res_x / 2;
}

void	mousespeed_calc(float speed, t_mlx_params *mlx)
{
	int		i;
	int		j;
	int		factor;
	float	step;

	mlx->input->mouse_speed = malloc(sizeof(float) * (mlx->map->res_x));
	mem_check(mlx->input->mouse_speed, mlx, 2, 30);
	i = 0;
	j = 0;
	factor = 100;
	step = mlx->map->res_x / 100;
	while (i < mlx->map->res_x / 2)
	{
		mlx->input->mouse_speed[i] = speed * factor;
		if ((float)(i++) >= j)
		{
			factor--;
			j += step;
		}
	}
	while (i < mlx->map->res_x)
	{
		mlx->input->mouse_speed[i] = speed * factor;
		if ((float)(i++) >= j)
		{
			factor++;
			j += step;
		}
	}
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
	if (mlx->input->mouse_x < mlx->map->res_x / 2)
	{
		rotate_pl(123, mlx, mlx->input->mouse_speed[mlx->input->mouse_x]);
	// 	// printf("%f\t%i\n", mlx->input->mouse_speed[mlx->input->mouse_x], mlx->input->mouse_x);
	}
	else if (mlx->input->mouse_x > mlx->map->res_x / 2)
	{
		rotate_pl(124, mlx, mlx->input->mouse_speed[mlx->input->mouse_x]);
	// 	// printf("%f\t%i\n", mlx->input->mouse_speed[mlx->input->mouse_x], mlx->input->mouse_x);
	}
	relocate(mlx);
	sprite_dist(mlx);
	return (0);
}

int	check_f_coords(char side, t_mlx_params *mlx, float speed)
{
	mlx->pl->f_x = mlx->pl->x;
	mlx->pl->f_y = mlx->pl->y;
	if (side == 'x')
		mlx->pl->f_x = mlx->pl->x + mlx->f->cam_x * speed;
	if (side == 'y')
		mlx->pl->f_y = mlx->pl->y + mlx->f->cam_y * speed;
	if (!wall_check(mlx->pl->f_x, mlx->pl->f_y, mlx))
		return (0);
	return (1);
}

int	check_b_coords(char side, t_mlx_params *mlx, float speed)
{
	mlx->pl->f_x = mlx->pl->x;
	mlx->pl->f_y = mlx->pl->y;
	if (side == 'x')
		mlx->pl->f_x = mlx->pl->x - mlx->f->cam_x * speed;
	if (side == 'y')
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
