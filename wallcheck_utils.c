/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcheck_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:24:07 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/19 12:47:10 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_valid_coord(int shft_x, int shft_y, t_mlx_params *mlx)
{
	if (mlx->r->s_x >= mlx->map->max_x || mlx->r->s_y >= mlx->map->max_y
		|| mlx->r->s_x - shft_x < 0 || mlx->r->s_y - shft_y < 0
		|| mlx->map->grid[(int)mlx->r->s_y - shft_y]
		[(int)mlx->r->s_x - shft_x] == '1')
		return (0);
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
