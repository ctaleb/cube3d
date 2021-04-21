/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:57:40 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/21 15:27:05 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_mlx_params	*mlx_data_init(int ac, char **av)
{
	t_mlx_params	*mlx;

	mlx = malloc(sizeof(t_mlx_params));
	mem_check(mlx, mlx, 2, 0);
	map_open(av[1], mlx);
	pl_init(mlx);
	fov_init(mlx);
	ray_init(mlx);
	mlx->ptr = mlx_init();
	mem_check(mlx->ptr, mlx, 2, -1);
	mlx->save = 0;
	if (ac == 2)
		mlx->win = mlx_new_window(mlx->ptr, mlx->map->res_x,
				mlx->map->res_y, "Cube 3D");
	else if (ac == 3 && !(ft_strncmp(av[2], "--save", 6)))
		mlx->save = 1;
	else if (ac == 3)
		error_handler(3, mlx, 12);
	if (!mlx->save)
		mem_check(mlx->win, mlx, 2, -1);
	img_init(mlx);
	texture_init(mlx);
	sprite_init(mlx);
	input_init(mlx);
	return (mlx);
}
