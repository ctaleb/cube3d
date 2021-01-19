/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:07:23 by ctaleb            #+#    #+#             */
/*   Updated: 2020/11/28 15:48:12 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		size;

	size = ft_strlen((char *)str) + 1;
	if (!(cpy = ft_calloc(size, sizeof(char))))
		return (NULL);
	ft_memcpy(cpy, str, size - 1);
	return (cpy);
}
