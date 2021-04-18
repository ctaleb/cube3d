/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:41:06 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/18 10:47:43 by ctaleb           ###   ########lyon.fr   */
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
		mlx->sp[i]->true_dist = mlx->sp[i]->dist;
		i++;
	}
}

void	sprite_sizer(int i, t_mlx_params *mlx)
{
	int		ray_height;
	int		size;
	float	ray;
	float	crouch_value;

	if (mlx->input->crouch)
		crouch_value = 2.3;
	else
		crouch_value = 2;
	ray = -mlx->f->fov + (((float)mlx->f->fov * 2)
			/ ((float)mlx->map->res_x))
		* ((float)mlx->map->res_x / 2 + mlx->sp[i]->r_x);
	mlx->sp[i]->dist *= cos(deg_rad(1) * ray);
	ray_height = (int)(mlx->map->res_y / mlx->sp[i]->dist);
	mlx->sp[i]->u_coord = - ((float)ray_height) / 2
		+ (float)mlx->map->res_y / crouch_value - 2;
	mlx->sp[i]->b_coord = (float)ray_height / 2
		+ (float)mlx->map->res_y / crouch_value + 2;
	size = mlx->sp[i]->b_coord - mlx->sp[i]->u_coord;
	mlx->sp[i]->l_coord = (float)mlx->map->res_x / 2
		+ mlx->sp[i]->r_x - size / 2;
	mlx->sp[i]->r_coord = (float)mlx->map->res_x / 2
		+ mlx->sp[i]->r_x + size / 2;
}

void	sprite_disable(int i, t_mlx_params *mlx)
{
	if (!mlx->sp[i]->active
		|| mlx->sp[i]->angle + 0.2 < -mlx->f->fov * 0.0174533
		|| mlx->sp[i]->angle - 0.2 > mlx->f->fov * 0.0174533)
		mlx->sp[i]->visible = 0;
}

void	health_change(int status, t_mlx_params *mlx)
{
	char	*argv[3];

	argv[0] = "cub3D";
	argv[1] = ft_strdup(mlx->map->nextlevel);
	argv[2] = NULL;
	if (status == 2)
	{
		free_all(mlx, 99);
		execve(argv[0], argv, NULL);
		exit(0);
	}
	else if (status == 1)
	{
		if (mlx->pl->health > 80)
			mlx->pl->health = 100;
		else
			mlx->pl->health += 20;
	}
	else
	{
		if (mlx->pl->health < 80)
			mlx->pl->health = 0;
		else
			mlx->pl->health -= 20;
	}
}

void	sprite_deactivate(int x, int y, int status, t_mlx_params *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map->sprite_nb)
	{
		if (mlx->sp[i]->active && (int)mlx->sp[i]->x == x
			&& (int)mlx->sp[i]->y == y)
		{
			if (mlx->sp[i]->dist <= 0.3)
			{
				health_change(status, mlx);
				mlx->sp[i]->active = 0;
			}
		}
		i++;
	}
}