/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:01:02 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/19 14:37:18 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	mem_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_all(t_mlx_params *mlx)
{
	int	i;

	mlx_destroy_image(mlx->ptr, mlx->img->ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mem_free(mlx->input);
	mem_free(mlx->f);
	mem_free(mlx->r);
	mem_free(mlx->sp_txt);
	mem_free(mlx->n_txt);
	if (mlx->sp)
	{
		i = 0;
		while (i < mlx->map->sprite_nb)
		{
			mem_free(mlx->sp[i]);
			i++;
		}
	}
}

void	error_handler(int ernum, t_mlx_params *mlx)
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
			free_all(mlx);
			exit(-1 * ernum);
		}
		free(line);
		i++;
	}
	close(fd);
	printf("Unexpected Error\n");
	exit(-99);
}

void	mem_check(void *ptr, t_mlx_params *mlx, int ernum)
{
	if (!ptr)
		error_handler(ernum, mlx);
}
