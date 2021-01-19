/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:46:12 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/19 15:29:52 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include "libft/libft.h"

typedef struct	s_map {
		int		**grid;
		int		**valid;
		int		size_x;
		int		size_y;
		char	*north_t;
		char	*south_t;
		char	*east_t;
		char	*west_t;
		char	*sprite_t;
		int		floor_c;
		int		ceiling_c;
}				t_map;

t_map			*map_open(char *path);
int				data_check(t_map *map_data);
void			error_handler(int ernum);

int				rgbtoi(int t, int r, int g, int b);

#endif
