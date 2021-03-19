/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_extractor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:00:22 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/19 10:57:26 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	data_check(t_map *map_data)
{
	if (map_data->res_x && map_data->res_y && map_data->north_t
		&& map_data->south_t && map_data->east_t && map_data->west_t
		&& map_data->sprite_t && map_data->floor_c >= 0
		&& map_data->ceiling_c >= 0)
		return (1);
	return (0);
}

int	get_colour(char *line, t_mlx_params *mlx)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (line[i] == ' ')
		i++;
	r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',')
		error_handler(21, mlx);
	g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',')
		error_handler(21, mlx);
	b = ft_atoi(&line[i]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		error_handler(22, mlx);
	return (rgbtoi(0, r, g, b));
}

char	*get_path(char *line, t_mlx_params *mlx)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (line[i] == ' ')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(&line[i]) + 1));
	mem_check(dest, mlx, 2);
	j = 0;
	while (line[i + j])
	{
		if (ft_isspace(line[i]))
			error_handler(21, mlx);
		dest[j] = line[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

void	get_resolution(t_map *map_data, char *line, t_mlx_params *mlx)
{
	int	i;

	if (map_data->res_x >= 0 || map_data->res_y >= 0)
		error_handler(23, mlx);
	i = 0;
	while (line[i] == ' ')
		i++;
	map_data->res_x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	map_data->res_y = ft_atoi(&line[i]);
	if (map_data->res_x > 5120 || map_data->res_y > 2880)
		error_handler(22, mlx);
}
