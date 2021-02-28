/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:14:24 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/28 15:22:34 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_sprite(t_texture *texture, t_mlx_params *mlx)
{
	int	tex_x;
	int	tex_y;

	tex_x = fmodf(mlx->r->nwall_x, 1) * texture->width;
	if (fmodf(mlx->r->nwall_x, 1) == 0)
		tex_x = fmodf(mlx->r->nwall_y, 1) * texture->width;
	tex_y = (mlx->r->pos - mlx->r->u_wall) * texture->height
		/ (mlx->r->l_wall - mlx->r->u_wall);
	if (tex_y > texture->height - 1)
		tex_y -= 1;
	my_mlx_pixel_put(mlx, mlx->r->id, mlx->r->pos,
		texture->addr[tex_y * texture->width + tex_x]);
}

void	sprite_check(t_mlx_params *mlx)
{
	put_sprite(mlx->sp_txt, mlx);
}