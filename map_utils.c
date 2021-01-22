/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:05:42 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/22 16:37:02 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		file_len(char *path)
{
	int		fd;
	int		i;
	char	*line;

	if ((fd = open(path, O_RDONLY)) < 0)
		error_handler(11);
	i = 0;
	while (ft_get_next_line(fd, 10, &line))
	{
		free(line);
		i++;
	}
	if (close(fd) < 0)
		error_handler(12);
	return (i);
}