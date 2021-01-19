/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:19:18 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/02 12:31:44 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) <= start)
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) < len)
		substr = ft_strdup(&s[start]);
	else
	{
		if (!(substr = ft_calloc(len + 1, sizeof(char))))
			return (NULL);
		i = 0;
		while (i < len)
		{
			substr[i] = s[start];
			start++;
			i++;
		}
	}
	return (substr);
}
