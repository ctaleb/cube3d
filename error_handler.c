/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:01:02 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/03 15:42:06 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	error_handler(int ernum, t_mlx_params *mlx, int stage)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("errors.txt", O_RDONLY);
	i = 0;
	while (ft_get_next_line(fd, 10, &line))
	{
		if (i == ernum)
		{
			printf("Error\nCode %s\n", line);
			free(line);
			close(fd);
			free_all(mlx, stage);
			exit(-1 * ernum);
		}
		free(line);
		i++;
	}
	close(fd);
	printf("Unexpected Error\n");
	exit(-99);
}

void	file_check(void *ptr, t_mlx_params *mlx, int j)
{
	int	i;

	if (ptr)
		return ;
	i = 0;
	while (i < j)
	{
		free(mlx->map->file[i]);
		i++;
	}
	error_handler(2, mlx, 3);
}

void	matrix_check(void *ptr, t_mlx_params *mlx, int j, int mode)
{
	int	i;

	if (ptr)
		return ;
	i = 0;
	if (mode == 0)
	{
		while (i < j)
		{
			free(mlx->map->grid[i]);
			i++;
		}
	}
	else
	{
		while (i < j)
		{
			free(mlx->map->dup[i]);
			i++;
		}
	}
	error_handler(2, mlx, 4);
}

void	sp_check(void *ptr, t_mlx_params *mlx, int j)
{
	int	i;

	if (ptr)
		return ;
	i = 0;
	while (i < j)
	{
		free(mlx->sp[i]);
		i++;
	}
	error_handler(2, mlx, 25);
}

void	mem_check(void *ptr, t_mlx_params *mlx, int ernum, int stage)
{
	if (!ptr)
		error_handler(ernum, mlx, stage);
}
