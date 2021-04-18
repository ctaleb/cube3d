/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:39:55 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/11 13:24:38 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
