/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:41:03 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/18 17:27:01 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	key_press(int keycode, t_mlx_params *mlx)
{
	if (keycode == 53)
	{
		free_all(mlx, 31);
		exit(0);
	}
	if (keycode == 126 || keycode == 13)
		mlx->input->forward = 1;
	if (keycode == 125 || keycode == 1)
		mlx->input->backward = 1;
	if (keycode == 123)
		mlx->input->rotate_l = 1;
	if (keycode == 124)
		mlx->input->rotate_r = 1;
	if (keycode == 0)
		mlx->input->strafe_l = 1;
	if (keycode == 2)
		mlx->input->strafe_r = 1;
	if (keycode == 257)
		mlx->input->crouch = 1;
	if (keycode == 49)
		mlx->input->action = 1;
	return (0);
}

int	key_release(int keycode, t_mlx_params *mlx)
{
	if (keycode == 126 || keycode == 13)
		mlx->input->forward = 0;
	if (keycode == 125 || keycode == 1)
		mlx->input->backward = 0;
	if (keycode == 123)
		mlx->input->rotate_l = 0;
	if (keycode == 124)
		mlx->input->rotate_r = 0;
	if (keycode == 0)
		mlx->input->strafe_l = 0;
	if (keycode == 2)
		mlx->input->strafe_r = 0;
	if (keycode == 257)
		mlx->input->crouch = 0;
	if (keycode == 49)
		mlx->input->action = 0;
	return (0);
}

int	mouse_move(int x, int y, t_mlx_params *mlx)
{
	(void)y;
	mlx->input->mouse_x = x;
	return (0);
}

void	action(t_mlx_params *mlx)
{
	int	x;
	int	y;
	int	i;

	x = (int)mlx->pl->x;
	y = (int)mlx->pl->y;
	if (mlx->map->grid[y][x] == 'K' && mlx->input->action)
	{
		i = 0;
		while (i < mlx->map->sprite_nb)
		{
			if ((int)mlx->sp[i]->x == x && (int)mlx->sp[i]->y == y)
				door_opener(mlx, i);
			i++;
		}
	}
}

void	input_init(t_mlx_params *mlx)
{
	mlx->input = malloc(sizeof(t_input));
	mem_check(mlx->input, mlx, 2, mlx->stage);
	mlx->input->forward = 0;
	mlx->input->backward = 0;
	mlx->input->strafe_l = 0;
	mlx->input->strafe_r = 0;
	mlx->input->rotate_l = 0;
	mlx->input->rotate_r = 0;
	mlx->input->crouch = 0;
	mlx->input->action = 0;
	if (!mlx->save)
		mlx_mouse_move(mlx->win, mlx->map->res_x / 2, mlx->map->res_y / 2);
	mlx->input->mouse_x = mlx->map->res_x / 2;
	mlx->input->mouse_y = mlx->map->res_x / 2;
}
