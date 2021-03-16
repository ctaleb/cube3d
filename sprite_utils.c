/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:51:23 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/16 11:09:38 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	sprite_swap(t_sprites **s1, t_sprites **s2)
{
	t_sprites *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	sprite_sort(t_mlx_params *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mlx->map->sprite_nb)
	{
		j = i + 1;
		while (j < mlx->map->sprite_nb)
		{
			if (mlx->sp[i]->dist < mlx->sp[j]->dist)
				sprite_swap(&mlx->sp[i], &mlx->sp[j]);
			j++;
		}
		i++;
	}
}

void	sprite_xpos(int i, t_mlx_params *mlx)
{
	mlx->sp[i]->d_x = mlx->sp[i]->x - mlx->pl->x;
	mlx->sp[i]->d_y = mlx->sp[i]->y - mlx->pl->y;
	mlx->sp[i]->r_x = (mlx->sp[i]->d_x * mlx->f->cam_x
		+ mlx->sp[i]->d_y * mlx->f->cam_y)
		/ (dist_calc(mlx->f->cam_x, mlx->f->cam_y)
		* (dist_calc(mlx->sp[i]->d_x, mlx->sp[i]->d_y)));
	// if (mlx->sp[i]->id == 1)
	// 	printf("id:%i\txa:%f\n", mlx->sp[i]->id, mlx->sp[i]->r_x);
	if (mlx->sp[i]->r_x > 1)
		mlx->sp[i]->r_x = 1;
	else if (mlx->sp[i]->r_x < -1)
		mlx->sp[i]->r_x = -1;

	// checks if the sprite is in the fov, but not precise enough
	if (acos(mlx->sp[i]->r_x) < -mlx->f->fov * 0.0174533 || acos(mlx->sp[i]->r_x) > mlx->f->fov * 0.0174533)
		mlx->sp[i]->visible = 0;

	// mlx->sp[i]->r_x = roundf((acos(mlx->sp[i]->r_x) / 0.0174533
	// 	* ((float)mlx->map->res_x / 2)) / mlx->f->fov);
	mlx->sp[i]->r_x = roundf((tan(acos(mlx->sp[i]->r_x))
		* ((float)mlx->map->res_x / 2)) / tan(deg_rad(mlx->f->fov)));
	mlx->sp[i]->r_x *= anglizer(mlx->f->cam_x, mlx->f->cam_y,
		mlx->sp[i]->d_x, mlx->sp[i]->d_y);
	// printf("r_x%f\n", mlx->sp[i]->r_x);
	// if (mlx->sp[i]->id == 1)
	// 	printf("xf:%f\n", mlx->sp[i]->r_x);
}

void	sprite_enable(int i, t_mlx_params *mlx)
{
	// float	dist1;
	// float	dist2;

	// dist1 = sqrtf(powf((mlx->sp[i]->x - (mlx->f->cam_x + mlx->pl->x)), 2) + powf(mlx->sp[i]->y - (mlx->f->cam_y + mlx->pl->y), 2));
	// dist2 = sqrtf(powf((mlx->sp[i]->x - (-mlx->f->cam_x + mlx->pl->x)), 2) + powf(mlx->sp[i]->y - (-mlx->f->cam_y + mlx->pl->y), 2));
	// if (dist1 >= dist2 - 1)
	// 	mlx->sp[i]->visible = 0;
}

// void	sprite_enable(t_mlx_params *mlx)
// {
// 	int	i;

// 	i = 0;
// 	while (i < mlx->map->sprite_nb)
// 	{
// 		if ((int)mlx->r->s_y == (int)mlx->sp[i]->y
// 			&& (int)mlx->r->s_x == (int)mlx->sp[i]->x)
// 			mlx->sp[i]->visible = 1;
// 		i++;
// 	}
// }

void	sprite_reset(t_mlx_params *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map->sprite_nb)
	{
		mlx->sp[i]->visible = 1;
		i++;
	}
}
