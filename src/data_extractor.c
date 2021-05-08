/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_extractor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:00:22 by ctaleb            #+#    #+#             */
/*   Updated: 2021/05/08 14:25:24 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	data_check(t_map *map_data)
{
	if (map_data->res_x > 0 && map_data->res_y > 0 && map_data->north
		&& map_data->south && map_data->east && map_data->west
		&& map_data->sp_t && map_data->flr_c >= 0
		&& map_data->clg_c >= 0
		&& map_data->sky_t && map_data->hb_t && map_data->food_t
		&& map_data->trap_t && map_data->tp_a_t && map_data->tp_b_t
		&& map_data->tp_c_t && map_data->tp_d_t && map_data->sp_b_t
		&& map_data->end_t && map_data->go_t && map_data->nlvl
		&& map_data->door && map_data->key_a && map_data->key_b
		&& map_data->music && map_data->m_len >= 0)
		return (1);
	return (0);
}

int	get_colour(char *line, int value, t_mlx_params *mlx)
{
	int	i;
	int	r;
	int	g;
	int	b;

	if (value >= 0)
		error_handler(23, mlx, 5);
	i = 0;
	i = space_dig(line, i, mlx);
	r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i = space_comma(line, i, mlx);
	g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i = space_comma(line, i, mlx);
	b = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] || r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		error_handler(22, mlx, 4);
	return (rgbtoi(0, r, g, b));
}

char	*get_path(char *line, char *dst, t_mlx_params *mlx, int mode)
{
	int		i;
	int		j;
	char	*dest;

	if (dst)
		error_handler(23, mlx, 4);
	i = 0;
	while (line[i] == ' ')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(&line[i]) + 1));
	mem_check(dest, mlx, 2, mlx->stage);
	j = 0;
	while (line[i + j])
	{
		if (ft_isspace(line[i]))
			error_handler(21, mlx, 4);
		dest[j] = line[i + j];
		j++;
	}
	dest[j] = '\0';
	if (mode)
		if (ft_strncmp(&dest[ft_strlen(dest) - 4], ".xpm", 5))
			error_handler(21, mlx, 2);
	return (dest);
}

void	get_resolution(t_map *map_data, char *line, t_mlx_params *mlx)
{
	int	i;

	if (map_data->res_x >= 0 || map_data->res_y >= 0)
		error_handler(23, mlx, 4);
	i = 0;
	i = space_dig(line, i, mlx);
	map_data->res_x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i = space_dig(line, i, mlx);
	map_data->res_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i])
		error_handler(22, mlx, 4);
	if (map_data->res_x > 2560 || map_data->res_y > 1440)
	{
		map_data->res_x = 2560;
		map_data->res_y = 1440;
	}
	else if (map_data->res_x == 0 || map_data->res_y == 0)
		error_handler(21, mlx, 1);
}
