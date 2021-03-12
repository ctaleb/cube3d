/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:51:23 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/12 14:20:18 by ctaleb           ###   ########lyon.fr   */
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
	mlx->sp[i]->r_x = ((mlx->sp[i]->x - mlx->pl->x) * mlx->f->cam_x
		+ (mlx->sp[i]->y - mlx->pl->y) * mlx->f->cam_y)
		/ (sqrtf(powf(mlx->f->cam_x, 2) + powf(mlx->f->cam_y, 2))
		* (sqrtf(powf(mlx->sp[i]->x - mlx->pl->x, 2)
		+ powf(mlx->sp[i]->y - mlx->pl->y, 2))));
	// mlx->sp[i]->r_x = ((mlx->sp[i]->x - mlx->pl->x) * mlx->f->cam_x
	// 	+ (mlx->sp[i]->y - mlx->pl->y) * mlx->f->cam_y)
	// 	/ (sqrtf(powf(mlx->f->cam_x, 2) + powf(mlx->f->cam_y, 2))
	// 	* (sqrtf(powf(mlx->sp[i]->x - mlx->pl->x, 2)
	// 	+ powf(mlx->sp[i]->y - mlx->pl->y, 2))));
	// if (mlx->sp[i]->id == 1)
	// 	printf("id:%i\txa:%f\n", mlx->sp[i]->id, mlx->sp[i]->r_x);
	if (mlx->sp[i]->r_x > 1)
		mlx->sp[i]->r_x = 1;
	else if (mlx->sp[i]->r_x < -1)
		mlx->sp[i]->r_x = -1;
	mlx->sp[i]->r_x = roundf((acos(mlx->sp[i]->r_x) / 0.0174533
		* ((float)mlx->map->res_x / 2)) / mlx->f->fov);
	mlx->sp[i]->r_x *= anglizer(mlx->f->cam_x, mlx->f->cam_y, mlx->sp[i]->x - mlx->pl->x, mlx->sp[i]->y - mlx->pl->y);
	// if (mlx->sp[i]->id == 1)
	// 	printf("xf:%f\n", mlx->sp[i]->r_x);
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

// void	sprite_reset(t_mlx_params *mlx)
// {
// 	int	i;

// 	i = 0;
// 	while (i < mlx->map->sprite_nb)
// 	{
// 		mlx->sp[i]->visible = 0;
// 		i++;
// 	}
// }
