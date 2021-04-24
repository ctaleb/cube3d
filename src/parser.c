/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:39:55 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/24 17:41:29 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	validate_data(t_mlx_params *mlx)
{
	if (mlx->map->res_x && mlx->map->res_y && mlx->map->north
		&& mlx->map->south && mlx->map->east && mlx->map->west
		&& mlx->map->sp_t && mlx->map->floor_c < 0
		&& mlx->map->ceiling_c < 0)
		error_handler(22, mlx, 4);
}

int	space_dig(char *line, int i, t_mlx_params *mlx)
{
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
		return (i);
	else
		error_handler(21, mlx, 4);
	return (i);
}

int	space_comma(char *line, int i, t_mlx_params *mlx)
{
	while (line[i] == ' ')
		i++;
	if (line[i] == ',')
		i++;
	else
		error_handler(21, mlx, 4);
	i = space_dig(line, i, mlx);
	return (i);
}
