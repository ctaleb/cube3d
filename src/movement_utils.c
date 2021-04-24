/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:47:45 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/24 17:09:01 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	{
		if (mlx->input->mouse_on)
			mlx_mouse_move(mlx->win, mlx->map->res_x / 2, mlx->map->res_y / 2);
	}
	mlx->input->mouse_x = mlx->map->res_x / 2;
	mlx->input->mouse_y = mlx->map->res_x / 2;
}
