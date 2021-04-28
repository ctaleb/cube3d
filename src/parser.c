/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:39:55 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/28 13:35:09 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	validate_mandatory(t_mlx_params *mlx)
{
	if (mlx->map->res_x && mlx->map->res_y && mlx->map->north
		&& mlx->map->south && mlx->map->east && mlx->map->west
		&& mlx->map->sp_t && mlx->map->floor_c < 0
		&& mlx->map->ceiling_c < 0)
		error_handler(22, mlx, 4);
}

void	unvalidator(int i, t_mlx_params *mlx)
{
	if (mlx->file[i][0] == '\0')
		return ;
	if (mlx->file[i][0] != 'R'
		&& (mlx->file[i][0] != 'N'
		&& (mlx->file[i][1] != 'L' || mlx->file[i][1] != 'O'))
		&& (mlx->file[i][0] != 'S' && mlx->file[i][1] != 'O')
		&& (mlx->file[i][0] != 'W' && mlx->file[i][1] != 'E')
		&& (mlx->file[i][0] != 'E' && mlx->file[i][1] != 'A')
		&& mlx->file[i][0] != 'F' && mlx->file[i][0] != 'C'
		&& (mlx->file[i][0] != 'O' && (mlx->file[i][1] != '1'
		|| mlx->file[i][1] != '2' || mlx->file[i][1] != '3'))
		&& (mlx->file[i][0] != 'B' && mlx->file[i][1] != 'X')
		&& (mlx->file[i][0] != 'H' && mlx->file[i][1] != 'B')
		&& (mlx->file[i][0] != 'G' && mlx->file[i][1] != 'O')
		&& (mlx->file[i][0] != 'T' && (mlx->file[i][1] != '1'
		|| mlx->file[i][1] != '2' || mlx->file[i][1] != '3'
		|| mlx->file[i][1] != '4')) && (mlx->file[i][0] != 'D'
		&& mlx->file[i][1] != 'C') && mlx->file[i][0] != 'K'
		&& (mlx->file[i][1] != '1' || mlx->file[i][1] != '2'))
		error_handler(22, mlx, 5);
	if (mlx->file[i][1] == '\0' || mlx->file[i][2] == '\0')
		error_handler(22, mlx, 5);
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
