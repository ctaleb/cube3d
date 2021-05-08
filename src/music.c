/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 14:22:25 by ctaleb            #+#    #+#             */
/*   Updated: 2021/05/08 16:14:00 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_len(char *line, int value, t_mlx_params *mlx)
{
	int	i;
	int	len;

	if (value >= 0)
		error_handler(23, mlx, 5);
	i = 0;
	i = space_dig(line, i, mlx);
	len = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] || len > 600 || len < 0)
		error_handler(22, mlx, 4);
	return (len);
}

void	read_music(int i, t_mlx_params *mlx)
{
	if (mlx->file[i][0] == 'M' && mlx->file[i][1] == 'C')
	{
		mlx->map->music = get_path(&mlx->file[i][2], mlx->map->music, mlx, 0);
		mlx->def->music = 1;
	}
	else if (mlx->file[i][0] == 'M' && mlx->file[i][1] == 'L')
	{
		mlx->map->m_len = get_len(&mlx->file[i][2], mlx->map->m_len, mlx);
		mlx->def->m_len = 1;
	}
}

void	music_cmd(t_mlx_params *mlx)
{
	char	*rdy;
	char	*suffix;
	char	*prefix;
	char	*len;

	if (mlx->save)
		return ;
	else if (mlx->def->music && mlx->def->m_len)
	{
		len = ft_itoa(mlx->map->m_len);
		mem_check(len, mlx, 2, 4);
		prefix = ft_strjoin("afplay -q 1 -t ", len);
		mem_check(prefix, mlx, 2, 4);
		suffix = ft_strjoin(prefix, " ");
		mem_check(suffix, mlx, 2, 4);
		rdy = ft_strjoin(suffix, mlx->map->music);
		mem_check(rdy, mlx, 2, 4);
		mlx->cmd = ft_strjoin(rdy, " &");
		mem_check(mlx->cmd, mlx, 2, 4);
		system(mlx->cmd);
	}
	else
		system("afplay -q 1 -t 78 ./src/audio/stage_1.mp3 &");
	mlx->time = clock();
}

void	music_reload(t_mlx_params *mlx)
{
	clock_t	new;

	if (mlx->save)
		return ;
	new = clock();
	if (mlx->def->music && mlx->def->m_len)
	{
		if (new >= mlx->time + mlx->map->m_len * 1000000)
		{
			system("killall afplay 2>/dev/null");
			system(mlx->cmd);
			mlx->time = clock();
		}
	}
	else
	{
		if (new >= mlx->time + 78000000)
		{
			system("killall afplay 2>/dev/null");
			system("afplay -q 1 -t 78 ./src/audio/stage_1.mp3 &");
			mlx->time = clock();
		}
	}
}
