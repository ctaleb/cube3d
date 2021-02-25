/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:10:38 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/25 13:04:27 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_wall(int start_ray, int end_ray, t_mlx_params *mlx)
{
	int tex_x;
	int tex_y;

	tex_x = fmodf(mlx->r->nwall_x, 1) * mlx->n_txt->width;
   if (fmodf(mlx->r->nwall_x, 1) == 0)
       tex_x = fmodf(mlx->r->nwall_y, 1) * mlx->n_txt->width;
	tex_y = (mlx->r->pos - start_ray) * mlx->n_txt->height / (end_ray - start_ray);
	my_mlx_pixel_put(mlx, mlx->r->id, mlx->r->pos, mlx->n_txt->addr[tex_y * mlx->n_txt->width + tex_x]);
}

void	put_ray(int start_ray, int end_ray, t_mlx_params *mlx)
{
	int	w_colour;

	mlx->r->pos = 0;
	if (mlx->r->dist_x < mlx->r->dist_y)
		w_colour = rgbtoi(0, 111, 111, 111);
	else
		w_colour = rgbtoi(0, 0, 111, 111);
	while (mlx->r->pos < mlx->map->res_y)
	{
		if (mlx->r->pos < start_ray)
			my_mlx_pixel_put(mlx, mlx->r->id, mlx->r->pos, mlx->map->ceiling_c);
		else if (mlx->r->pos >= start_ray && mlx->r->pos <= end_ray)
			put_wall(start_ray, end_ray, mlx);
			// my_mlx_pixel_put(mlx, index, y, w_colour);
		else
			my_mlx_pixel_put(mlx, mlx->r->id, mlx->r->pos, mlx->map->floor_c);
		mlx->r->pos++;
	}
	
}

void	ray_cannon(float fish, t_mlx_params *mlx)
{
	float	ray_len;
	int		ray_height;
	int		start_ray;
	int		end_ray;

	//printf("distx%f\tdisty%f\n", mlx->r->dist_x, mlx->r->dist_y);
	//exit(1);
	
	if (mlx->r->dist_x < mlx->r->dist_y && mlx->r->dist_x != 0)
		ray_len = mlx->r->dist_x * fish;
	else
		ray_len = mlx->r->dist_y * fish;
	//printf("raynum %i\traylen %f\n", index, ray_len);
	// getchar(); 
	
	ray_height = (int)((mlx->map->res_y / ray_len));
	start_ray = -(ray_height) / 2 + mlx->map->res_y / 2;
	if (start_ray < 0)
		start_ray = 0;
	end_ray = ray_height / 2 + mlx->map->res_y / 2;
	if (end_ray >= mlx->map->res_y)
		end_ray = mlx->map->res_y - 1;
	put_ray(start_ray, end_ray, mlx);
	//printf("s%i\te%i\n", start_ray, end_ray);
}