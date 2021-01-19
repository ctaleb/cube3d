/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_extractor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:00:22 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/19 16:17:37 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		data_check(t_map *map_data)
{
	if (map_data->size_x && map_data->size_y && map_data->north_t
			&& map_data->south_t && map_data->east_t && map_data->west_t
			&& map_data->sprite_t && map_data->floor_c && map_data->ceiling_c)
		return (1);
	return (0);
}

void	get_colour(int n, char *line)
{
	int i;
	int r;
	int g;
	int b;

	i = 0;
	if (line[i] != 'C' || line[i] != 'F')
		error_handler(21);
	i++;
	while (line[i] == ' ')
		i++;
	r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',')
		error_handler(21);
	g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',')
		error_handler(21);
	b = ft_atoi(&line[i]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		error_handler(22);
}