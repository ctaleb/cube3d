/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:57:40 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/01 13:26:55 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_mlx_params	*mlx_data_init(int ac, char **av)
{
	t_mlx_params	*mlx;

	mlx = malloc(sizeof(t_mlx_params));
	mem_check(mlx, mlx, 2, 0);
	map_open(av[1], mlx);
	free_matrix(mlx, 1);
	pl_init(mlx);
	fov_init(mlx);
	ray_init(mlx);
	mlx->ptr = mlx_init();
	mem_check(mlx->ptr, mlx, 2, 12);
	if (ac == 3 && !(ft_strncmp(av[2], "--save", 6)))
		mlx->save = 1;
	else
	{
		mlx->save = 0;
		mlx->win = mlx_new_window(mlx->ptr, mlx->map->res_x,
				mlx->map->res_y, "Cube 3D");
	}
	mem_check(mlx->win, mlx, 2, 13);
	img_init(mlx);
	texture_init(mlx);
	sprite_init(mlx);
	input_init(mlx);
	return (mlx);
}
