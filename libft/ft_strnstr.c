/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:00:43 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/23 15:27:21 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	findlength(const char *needle)
{
	size_t	c;

	c = 0;
	while (needle[c] != '\0')
	{
		{
			c++;
		}
	}
	return (c);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	lon;
	size_t	g;

	i = 0;
	g = findlength(needle);
	if (g == 0)
	{
		return ((char *)haystack);
	}
	while (haystack[i] != '\0' && i < len)
	{
		lon = 0;
		while (haystack[i + lon] == needle[lon] && (i + lon) < len
			&& needle[lon] != '\0')
		{
			lon++;
			if (lon == g)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
