/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:10:38 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/18 13:23:22 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_ray(int index, int start_ray, int end_ray, t_mlx_params *mlx)
{
	int y;
	int	w_colour;

	y = 0;
	if (mlx->pl->dist_x < mlx->pl->dist_y)
		w_colour = rgbtoi(0, 111, 111, 111);
	else
		w_colour = rgbtoi(0, 0, 111, 111);
	while (y < mlx->map->size_y)
	{
		if (y < start_ray)
			my_mlx_pixel_put(mlx, index, y, mlx->map->ceiling_c);
		else if (y >= start_ray && y <= end_ray)
			my_mlx_pixel_put(mlx, index, y, w_colour);
		else
			my_mlx_pixel_put(mlx, index, y, mlx->map->floor_c);
		y++;
	}
	
}

void	ray_cannon(float fish, int index, t_mlx_params *mlx)
{
	float	ray_len;
	int		ray_height;
	int		start_ray;
	int		end_ray;

	//printf("x%f\ty%f\ndistx%f\tdisty%f\n", x, y, mlx->pl->dist_x, mlx->pl->dist_y);
	//exit(1);
	if (mlx->pl->dist_x < mlx->pl->dist_y)
		ray_len = mlx->pl->dist_x;
	else
		ray_len = mlx->pl->dist_y;
	// if (x >= 0 || y >= 0)
	// 	ray_len = sqrtf (exp2f(x - mlx->pl->x) + exp2f(y - mlx->pl->y));
	// else if (x < 0 || y < 0)
	// 	ray_len = len;
	ray_height = (int)((mlx->map->size_y / ray_len));
	start_ray = -(ray_height) / 2 + mlx->map->size_y / 2;
	if (start_ray < 0)
		start_ray = 0;
	end_ray = ray_height / 2 + mlx->map->size_y / 2;
	if (end_ray >= mlx->map->size_y)
		end_ray = mlx->map->size_y - 1;
	put_ray(index, start_ray, end_ray, mlx);
	//printf("s%i\te%i\n", start_ray, end_ray);
}