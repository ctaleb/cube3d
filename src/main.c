/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:36:57 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/24 17:08:16 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	exit_window(t_mlx_params *mlx)
{
	free_all(mlx, 31);
	exit(0);
}

void	ender(t_mlx_params *mlx)
{
	char	*argv[3];

	if (mlx->def->ending && !mlx->def->nxt_lvl)
		mlx->finished = 1;
	else if (mlx->def->nxt_lvl)
	{
		argv[0] = "cub3D";
		argv[1] = ft_strdup(mlx->map->nlvl);
		argv[2] = NULL;
		free_all(mlx, 99);
		execve(argv[0], argv, NULL);
	}
	else
	{
		free_all(mlx, 99);
		exit (0);
	}
}

void	put_ending(t_mlx_params *mlx)
{
	int	tex_x;
	int	tex_y;
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map->res_y)
	{
		x = 0;
		while (x < mlx->map->res_x)
		{
			tex_x = x * mlx->ending->width / mlx->map->res_x;
			tex_y = y * mlx->ending->height / mlx->map->res_y;
			my_mlx_pixel_put(mlx, x, y,
				mlx->ending->addr[tex_y * mlx->ending->width + tex_x]);
			x++;
		}
		y++;
	}
}

void	put_gameover(t_mlx_params *mlx)
{
	int	tex_x;
	int	tex_y;
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map->res_y)
	{
		x = 0;
		while (x < mlx->map->res_x)
		{
			tex_x = x * mlx->gameover->width / mlx->map->res_x;
			tex_y = y * mlx->gameover->height / mlx->map->res_y;
			my_mlx_pixel_put(mlx, x, y,
				mlx->gameover->addr[tex_y * mlx->gameover->width + tex_x]);
			x++;
		}
		y++;
	}
}

int	main(int ac, char *av[])
{
	t_mlx_params	*mlx;

	if (ac > 3 || ac < 2)
		error_handler(1, NULL, -9);
	mlx = mlx_data_init(ac, av);
	if (!mlx->save)
	{
		mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
		mlx_hook(mlx->win, 3, 1L << 1, key_release, mlx);
		mlx_hook(mlx->win, 6, 1L << 6, mouse_move, mlx);
		mlx_hook(mlx->win, 17, 1L << 17, exit_window, mlx);
	}
	mlx_loop_hook(mlx->ptr, frame_gen, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
