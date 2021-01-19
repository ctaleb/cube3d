/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:54:06 by ctaleb            #+#    #+#             */
/*   Updated: 2020/11/26 15:57:12 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(str = ft_calloc(size, sizeof(char))))
		return (NULL);
	ft_strlcat(str, s1, size);
	ft_strlcat(str, s2, size);
	return (str);
}
