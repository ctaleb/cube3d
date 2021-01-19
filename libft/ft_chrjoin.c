/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:54:06 by ctaleb            #+#    #+#             */
/*   Updated: 2020/11/26 15:57:12 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrjoin(char const *s1, char const c)
{
	int		size;
	char	*str;

	if (!s1 || !c)
		return (NULL);
	size = ft_strlen((char *)s1) + 2;
	if (!(str = ft_calloc(size, sizeof(char))))
		return (NULL);
	ft_strlcat(str, s1, size);
	str[size - 2] = c;
	return (str);
}
