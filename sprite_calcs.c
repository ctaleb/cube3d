/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:41:06 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/08 16:42:10 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	sprite_dist(t_mlx_params *mlx)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	while (i < mlx->map->sprite_nb)
	{
		x = mlx->sp[i]->x;
		y = mlx->sp[i]->y;
		mlx->sp[i]->dist = sqrtf(powf(x - mlx->pl->x, 2)
				+ powf(y - mlx->pl->y, 2));
		i++;
	}
}

void	sprite_sizer(int i, t_mlx_params *mlx)
{
	int	d_wall;
	int	u_sp;
	int	l_sp;
	int	ray_height;
	
	// mlx->sp[i]->size_x = mlx->sp_txt->width * mlx->sp[i]->dist;
	// mlx->sp[i]->size_y = mlx->sp_txt->height * mlx->sp[i]->dist;
	ray_height = (int)(mlx->map->res_y / mlx->sp[i]->dist);
	u_sp = - ((float)ray_height) / 2 + (float)mlx->map->res_y / 2;
	l_sp = (float)ray_height / 2 + (float)mlx->map->res_y / 2;
	// mlx->sp[i]->size_x = mlx->sp_txt->width * ((d_wall - mlx->sp[i]->dist) / d_wall);
	// mlx->sp[i]->size_y = mlx->sp_txt->height * ((d_wall - mlx->sp[i]->dist) / d_wall);
	if (mlx->sp[i]->id == 0)
		printf("%i\t%i\t%i\n", i, u_sp, l_sp);
}