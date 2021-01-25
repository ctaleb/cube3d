/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:57:40 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/25 13:17:03 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_mlx_params	*mlx_data_init(char *path)
{
	t_mlx_params	*mlx_prms;
	t_map			*map_data;
	t_player		*pl_data;

	if (!(map_data = map_open(path)))
		error_handler(0);
	if (!(mlx_prms = malloc(sizeof(t_mlx_params))))
		error_handler(2);
	mlx_prms->map = map_data;
	pl_data = pl_init(map_data);
	mlx_prms->pl_data = pl_data;
	mlx_prms->ptr = mlx_init();
	mlx_prms->win = mlx_new_window(mlx_prms->ptr, mlx_prms->map->size_x,
		mlx_prms->map->size_y, "Cube 3D");
	return(mlx_prms);
}
