/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:14:24 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/01 12:14:33 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_sprite_pixel(int i, int x, t_texture *texture, t_mlx_params *mlx)
{
	int	y;
	int	tex_x;
	int	tex_y;
	int	colour;

	y = mlx->sp[i]->u_coord;
	while (y < mlx->sp[i]->b_coord)
	{
		if (y >= 0 && y < mlx->map->res_y)
		{
			tex_x = (x - mlx->sp[i]->l_coord) * texture->width
				/ (mlx->sp[i]->r_coord - mlx->sp[i]->l_coord);
			tex_y = (y - mlx->sp[i]->u_coord) * texture->height
				/ (mlx->sp[i]->b_coord - mlx->sp[i]->u_coord);
			if (texture->addr[tex_y * texture->width + tex_x])
			{
				colour = trgbmod(texture->addr[tex_y * texture->width + tex_x],
						1 - (int)mlx->sp[i]->dist * 0.05);
				my_mlx_pixel_put(mlx, x, y, colour);
			}
		}
		y++;
	}
}

void	put_sprite(int i, t_texture *texture, t_mlx_params *mlx)
{
	int	x;

	if (!mlx->sp[i]->visible)
		return ;
	x = mlx->sp[i]->l_coord;
	while (x < mlx->sp[i]->r_coord)
	{
		if (x >= 0 && x < mlx->map->res_x && mlx->sp[i]->dist < mlx->f->dist[x])
			put_sprite_pixel(i, x, texture, mlx);
		x++;
	}
}

void	sprite_check(t_mlx_params *mlx)
{
	int	i;

	sprite_sort(mlx);
	i = 0;
	while (i < mlx->map->sprite_nb)
	{
		if (mlx->sp[i]->dist > 0.1)
		{
			sprite_xpos(i, mlx);
			sprite_sizer(i, mlx);
			sprite_disable(i, mlx);
			put_sprite(i, mlx->sp_txt, mlx);
		}
		i++;
	}
}
