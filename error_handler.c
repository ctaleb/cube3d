/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:01:02 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/23 15:19:28 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	error_handler(int ernum)
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
			exit(-1 * ernum);
		}
		free(line);
		i++;
	}
	close(fd);
	printf("Unexpected Error\n");
	exit(-99);
}
