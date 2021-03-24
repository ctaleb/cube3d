/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:30:10 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/24 15:24:52 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_file(t_mlx_params *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map->file_len)
	{
		printf("%i\n", i);
		free(mlx->map->file[i]);
		i++;
	}
}

void	free_matrix(t_mlx_params *mlx)
{
	int	i;

	i = 0;
	while (mlx->map->grid[i])
	{
		free(mlx->map->grid[i]);
		free(mlx->map->dup[i]);
		i++;
	}
}

void	free_sp(t_mlx_params *mlx)
{
	int	i;

	if (mlx->map->sprite_nb == 0)
		return ;
	i = 0;
	while (i < mlx->map->sprite_nb)
	{
		free(mlx->sp[i]);
		i++;
	}
}

void	free_all(t_mlx_params *mlx, int stage)
{
	if (stage >= 28)
		free(mlx->input);
	if (stage >= 27)
		mlx_destroy_image(mlx->ptr, mlx->sp_txt->ptr);
	if (stage >= 26)
		free(mlx->sp_txt);
	if (stage >= 25)
		free_sp(mlx);
	if (stage >= 24)
		free(mlx->sp);
	if (stage >= 23)
		mlx_destroy_image(mlx->ptr, mlx->w_txt->ptr);
	if (stage >= 22)
		mlx_destroy_image(mlx->ptr, mlx->e_txt->ptr);
	if (stage >= 21)
		mlx_destroy_image(mlx->ptr, mlx->s_txt->ptr);
	if (stage >= 20)
		mlx_destroy_image(mlx->ptr, mlx->n_txt->ptr);
	if (stage >= 19)
		free(mlx->w_txt);
	if (stage >= 18)
		free(mlx->e_txt);
	if (stage >= 17)
		free(mlx->s_txt);
	if (stage >= 16)
		free(mlx->n_txt);
	if (stage >= 15)
		// mlx_destroy_image(mlx, mlx->img->ptr);
	if (stage >= 14)
		free(mlx->img);
	if (stage >= 13)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (stage >= 12)
		free(mlx->ptr);
	if (stage >= 11)
		free(mlx->r);
	if (stage >= 10)
		free(mlx->f->dist);
	if (stage >= 9)
		free(mlx->f);
	if (stage >= 8)
		free(mlx->pl);
	if (stage >= 7)
		free_matrix(mlx);
	if (stage >= 6)
		free(mlx->map->dup);
	if (stage >= 5)
		free(mlx->map->grid);
	if (stage >= 4)
		// free_file(mlx);
	if (stage >= 3)
		// free(mlx->map->file);
	if (stage >= 2)
		free(mlx->map);
	if (stage >= 1)
		free(mlx);
}
