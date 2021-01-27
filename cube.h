/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:46:12 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/27 15:42:41 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct	s_map {
	char		**file;
	char		**grid;
	int			max_y;
	int			max_x;
	char		**dup;
	int			start_x;
	int			start_y;
	int			size_x;
	int			size_y;
	char		*north_t;
	char		*south_t;
	char		*east_t;
	char		*west_t;
	char		*sprite_t;
	int			floor_c;
	int			ceiling_c;
}				t_map;

typedef struct	s_player {
	float		x;
	float		y;
	float		cam_x;
	float		cam_y;
	int			colour;
}				t_player;


typedef struct	s_mlx_parmas {
	void		*ptr;
	void		*win;
	t_map		*map;
	t_player	*pl;
}				t_mlx_params;

t_map			*map_open(char *path);

int				file_len(char *path);
int				is_map(char *line);
int				analyne(t_map *map_data, char *line);

int				data_check(t_map *map_data);
void			start_check(t_map *map_data);
void			map_check(int x, int y, t_map *map_data);

void			map_data_init(t_map *map_data, char *path);
void			grid_init(t_map *map_data);
void			map_init(t_map *map_data);
t_mlx_params	*mlx_data_init(char *path);
t_player		*pl_init(t_map *map_data);

void			print_minimap(t_mlx_params *mlx);
void			put_map(int x, int y, t_mlx_params *mlx);
void			put_player(t_mlx_params *mlx);
void			rem_player(t_mlx_params *mlx);
void			put_camera(t_mlx_params *mlx);
void			rem_camera(t_mlx_params *mlx);

int				movement(int keycode, t_mlx_params *mlx);
int				move_pl(int keycode, t_mlx_params *mlx);
int				rotate_pl(int keycode, t_mlx_params *mlx);
int				check_coords(char dir, t_mlx_params *mlx);

int				escape_key(int keycode);

int				get_colour(char *line);
char			*get_path(char *line);
void			get_map(char **grid, int maxlen, char *line);
void			dup_map(char **grid, char **dup);
void			get_resolution(t_map *map_data, char *line);

void			error_handler(int ernum);

int				rgbtoi(int t, int r, int g, int b);

#endif
