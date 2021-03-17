/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcheck_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:24:07 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/17 09:38:03 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_valid_coord(float x, float y, int shft_x, int shft_y, t_mlx_params *mlx)
{
	if (x >= mlx->map->max_x || y >= mlx->map->max_y
			|| x - shft_x < 0 || y - shft_y < 0
			|| mlx->map->grid[(int)y - shft_y]
			[(int)x - shft_x] == '1')
		return (0);
	return (1);
}