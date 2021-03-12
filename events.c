/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:41:03 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/10 12:51:29 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		key_press(int keycode, t_mlx_params *mlx)
{
	if (keycode == 53)
		exit(0);
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
	return (0);
}

int		key_release(int keycode, t_mlx_params *mlx)
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
	return (0);
}

void	input_init(t_mlx_params *mlx)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (!input)
		error_handler(2);
	input->forward = 0;
	input->backward = 0;
	input->strafe_l = 0;
	input->strafe_r = 0;
	input->rotate_l = 0;
	input->rotate_r = 0;
	mlx->input = input;
}