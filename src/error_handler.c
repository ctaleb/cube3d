/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:01:02 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/28 17:24:18 by ctaleb           ###   ########lyon.fr   */
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

void	mem_check(void *ptr, t_mlx_params *mlx, int ernum, int stage)
{
	if (!ptr)
		error_handler(ernum, mlx, stage);
	if (stage == 0)
		mlx->stage = 0;
	else if (stage > 0)
		mlx->stage++;
	if (stage >= 0)
		mlx->memory[mlx->stage] = ptr;
	if (mlx->stage + 1 > 500)
		error_handler(5, mlx, stage);
}
