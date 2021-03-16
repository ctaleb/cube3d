/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:14:24 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/16 11:15:49 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_sprite(int i, t_texture *texture, t_mlx_params *mlx)
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
	
	if (!mlx->sp[i]->visible)
		return ;
	x = mlx->sp[i]->l_coord;
	while (x < mlx->sp[i]->r_coord)
	{
		if (x >= 0 && x < mlx->map->res_x && mlx->sp[i]->dist < mlx->f->dist[x])
		{
			y = mlx->sp[i]->u_coord;
			while (y < mlx->sp[i]->b_coord)
			{
				if (y >= 0 && y < mlx->map->res_y)
				{
					tex_x = (x - mlx->sp[i]->l_coord) * texture->width / (mlx->sp[i]->r_coord - mlx->sp[i]->l_coord);
					tex_y = (y - mlx->sp[i]->u_coord) * texture->height
						/ (mlx->sp[i]->b_coord - mlx->sp[i]->u_coord);
					if (texture->addr[tex_y * texture->width + tex_x])
					{
						my_mlx_pixel_put(mlx, x, y,
							texture->addr[tex_y * texture->width + tex_x]);
					}
				}
				y++;
			}
		}
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
			// sprite_enable(i, mlx);
			put_sprite(i, mlx->sp_txt, mlx);
		}
		i++;
	}
}
