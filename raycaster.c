/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:10:38 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/31 15:36:50 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_wall(t_texture *texture, t_mlx_params *mlx)
{
	int	tex_x;
	int	tex_y;
	int	colour;

	tex_x = fmodf(mlx->r->nwall_x, 1) * texture->width;
	if (fmodf(mlx->r->nwall_x, 1) == 0)
		tex_x = fmodf(mlx->r->nwall_y, 1) * texture->width;
	tex_y = (mlx->r->pos - mlx->r->u_wall) * texture->height
		/ (mlx->r->l_wall - mlx->r->u_wall);
	if (tex_y > texture->height - 1)
		tex_y -= 1;
	colour = trgbmod(texture->addr[tex_y * texture->width + tex_x], mlx->f->mod);
	// printf("%i\n", mlx->f->mod);
	my_mlx_pixel_put(mlx, mlx->r->id, mlx->r->pos, colour);
	/*texture->addr[tex_y * texture->width + tex_x] + rgbtoi(250, 0, 0, 0)*/
}

t_texture	*select_wall(t_mlx_params *mlx)
{
	if (mlx->r->side == 1 && mlx->f->cam_x >= 0)
		return (mlx->e_txt);
	else if (mlx->r->side == 1 && mlx->f->cam_x < 0)
		return (mlx->w_txt);
	else if (mlx->f->cam_y < 0)
		return (mlx->n_txt);
	else
		return (mlx->s_txt);
}

void	put_ray(t_mlx_params *mlx)
{
	int	ceiling;
	int	floor;

	mlx->r->pos = 0;
	if (mlx->r->dist_x < mlx->r->dist_y)
		mlx->r->side = 1;
	else
		mlx->r->side = 0;
	while (mlx->r->pos < mlx->map->res_y)
	{
		if (mlx->r->pos < mlx->r->u_wall)
		{
			// ceiling = trgbmod(mlx->map->ceiling_c, mlx->f->shade[mlx->r->pos]);
			my_mlx_pixel_put(mlx, mlx->r->id, mlx->r->pos, mlx->f->shade[mlx->r->pos]);
		}
		else if (mlx->r->pos >= mlx->r->u_wall && mlx->r->pos <= mlx->r->l_wall)
			put_wall(select_wall(mlx), mlx);
		else
		{
			// floor = trgbmod(mlx->map->floor_c, mlx->f->shade[mlx->r->pos]);
			my_mlx_pixel_put(mlx, mlx->r->id, mlx->r->pos, mlx->f->shade[mlx->r->pos]);
		}
		mlx->r->pos++;
	}
}

void	ray_cannon(float fish, t_mlx_params *mlx)
{
	float	ray_len;
	int		ray_height;

	if (mlx->r->dist_x < mlx->r->dist_y && mlx->r->dist_x != 0)
		ray_len = mlx->r->dist_x * fish;
	else
		ray_len = mlx->r->dist_y * fish;
	mlx->f->dist[mlx->r->id] = ray_len;
	mlx->f->mod = 1 - (int)ray_len * 0.05;
	ray_height = (int)((mlx->map->res_y / ray_len)) + 1;
	mlx->r->u_wall = roundf(- ((float)ray_height) / 2
			+ (float)mlx->map->res_y / 2);
	mlx->r->l_wall = (float)ray_height / 2 + (float)mlx->map->res_y / 2;
	put_ray(mlx);
}
