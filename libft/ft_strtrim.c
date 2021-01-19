/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:08:21 by ctaleb            #+#    #+#             */
/*   Updated: 2020/11/29 16:52:39 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]) != NULL && s1[start])
		start++;
	end = ft_strlen(s1) - 1;
	if (start == end + 1)
	{
		if (!(str = ft_calloc(1, sizeof(char))))
			return (NULL);
		return (str);
	}
	while (end >= 0 && ft_strrchr(set, s1[end]) != NULL)
		end--;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
