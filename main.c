/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:36:57 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/01 14:01:21 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	exit_window(t_mlx_params *mlx)
{
	free_all(mlx, 29);
	exit(0);
}

int	main(int ac, char *av[])
{
	t_mlx_params	*mlx;

	if (ac > 3)
		error_handler(1, NULL, 0);
	mlx = mlx_data_init(ac, av);
	if (!mlx->save)
	{
		mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
		mlx_hook(mlx->win, 3, 1L << 1, key_release, mlx);
		mlx_hook(mlx->win, 17, 1L << 17, exit_window, mlx);
	}
	mlx_loop_hook(mlx->ptr, frame_gen, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
