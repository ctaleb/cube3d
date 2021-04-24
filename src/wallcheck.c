/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:59:41 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/24 13:41:43 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_valid_coord(int shft_x, int shft_y, t_mlx_params *mlx, int mode)
{
	int	x;
	int	y;

	x = mlx->r->s_x - shft_x;
	y = mlx->r->s_y - shft_y;
	if (mlx->r->s_x >= mlx->map->max_x || mlx->r->s_y >= mlx->map->max_y
		|| x < 0 || y < 0 || mlx->map->grid[(int)y][(int)x] == '1'
		|| mlx->map->grid[(int)y][(int)x] == '3'
		|| mlx->map->grid[(int)y][(int)x] == '7')
	{
		if (x >= 0 && y >= 0 && x < mlx->map->max_x && y < mlx->map->max_y)
		{
			if (mode && mlx->map->grid[(int)y][(int)x] == '1')
				mlx->r->nt_y = 1;
			else if (mode && mlx->map->grid[(int)y][(int)x] == '7')
				mlx->r->nt_y = 7;
			else if (mlx->map->grid[(int)y][(int)x] == '1')
				mlx->r->nt_x = 1;
			else if (mlx->map->grid[(int)y][(int)x] == '7')
				mlx->r->nt_x = 7;
		}
		return (0);
	}
	return (1);
}

void	inverse_cam(char dir, t_mlx_params *mlx)
{
	if (dir == 'B')
	{
		mlx->f->cam_x *= -1;
		mlx->f->cam_y *= -1;
	}
}

int	wall_check(float x, float y, t_mlx_params *mlx)
{
	if (mlx->map->grid[(int)y][(int)x] == '1'
		|| mlx->map->grid[(int)y][(int)x] == '2'
		|| mlx->map->grid[(int)y][(int)x] == '4'
		|| mlx->map->grid[(int)y][(int)x] == '7')
		return (0);
	else if (mlx->map->grid[(int)y][(int)x] == '5')
		sprite_deactivate(x, y, 1, mlx);
	else if (mlx->map->grid[(int)y][(int)x] == '6')
		sprite_deactivate(x, y, 0, mlx);
	else if (mlx->map->grid[(int)y][(int)x] == '9')
		sprite_deactivate(x, y, 2, mlx);
	return (1);
}
