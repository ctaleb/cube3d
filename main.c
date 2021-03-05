/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:36:57 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/15 11:20:43 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char *av[])
{
	t_mlx_params	*mlx;

	if (ac != 2)
		error_handler(1);
	mlx = mlx_data_init(av[1]);
	mlx_key_hook(mlx->win, escape_key, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, movement, mlx);
	mlx_loop_hook(mlx->ptr, frame_gen, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
