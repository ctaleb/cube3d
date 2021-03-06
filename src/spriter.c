/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:14:24 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/21 12:10:56 by ctaleb           ###   ########lyon.fr   */
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
						0 + (int)mlx->sp[i]->dist * 0.05);
				my_mlx_multi_put(mlx, x, y, colour);
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
		if (x < 0)
			x++;
		else
			x += mlx->f->multi;
	}
}

static t_texture	*sub_selector(t_mlx_params *mlx, int i, int mode)
{
	if (mode == 1)
	{
		mlx->sp[i]->state++;
		if (mlx->sp[i]->state > 21)
			mlx->sp[i]->state = 0;
		if (mlx->sp[i]->state <= 6)
			return (mlx->tp_a);
		else if (mlx->sp[i]->state <= 11)
			return (mlx->tp_b);
		else if (mlx->sp[i]->state <= 16)
			return (mlx->tp_c);
		else if (mlx->sp[i]->state <= 21)
			return (mlx->tp_d);
	}
	else
	{
		if (mlx->sp[i]->state == 0)
			return (mlx->key_a);
		else
			return (mlx->key_b);
	}
	return (mlx->sp_txt);
}

t_texture	*sprite_select(t_mlx_params *mlx, int i)
{
	if (mlx->sp[i]->type == 4 && mlx->def->sec_sp)
		return (mlx->sec_sp);
	else if (mlx->sp[i]->type == 5 && mlx->def->h_pickup)
		return (mlx->h_pickup);
	else if (mlx->sp[i]->type == 6 && mlx->def->d_pickup)
		return (mlx->d_pickup);
	else if (mlx->sp[i]->type == 9 && mlx->def->tp_a
		&& mlx->def->tp_b && mlx->def->tp_c && mlx->def->tp_d)
		return (sub_selector(mlx, i, 1));
	else if (mlx->sp[i]->type == 10 && mlx->def->key_a
		&& mlx->def->key_b)
		return (sub_selector(mlx, i, 0));
	return (mlx->sp_txt);
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
			put_sprite(i, sprite_select(mlx, i), mlx);
		}
		i++;
	}
}
