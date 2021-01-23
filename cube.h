/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:46:12 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/23 15:32:41 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include "libft/libft.h"

typedef struct	s_map {
		char	**file;
		char	**grid;
		int		grid_hgt;
		int		grid_len;
		char	**dup;
		int		start_x;
		int		start_y;
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
int				file_len(char *path);
int				data_check(t_map *map_data);
void			start_check(t_map *map_data);
void			map_check(int x, int y, t_map *map_data);

void			map_data_init(t_map *map_data, char *path);
void			grid_init(t_map *map_data);
void			map_init(t_map *map_data);

int				get_colour(char *line);
char			*get_path(char *line);
void			get_map(char **grid, int maxlen, char *line);
void			dup_map(char **grid, char **dup);
void			get_resolution(t_map *map_data, char *line);

void			error_handler(int ernum);

int				rgbtoi(int t, int r, int g, int b);

#endif
