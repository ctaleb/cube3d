/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:01:02 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/18 13:11:44 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	error_handler(int ernum)
{
	if (ernum == 1)
	{
		printf("Error\nCode %i: Invalid argument count\n", ernum);
		exit (-1 * ernum);
	}
	if (ernum == 0)
	{
		printf("Error\nCode %i: Something went wrong\n", ernum);
		exit (-1 * ernum);
	}
	if (ernum == 11)
	{
		printf("Error\nCode %i: File not found\n", ernum);
		exit (-1 * ernum);
	}
	if (ernum == 12)
	{
		printf("Error\nCode %i: Couldn't close file\n", ernum);
		exit (-1 * ernum);
	}
}