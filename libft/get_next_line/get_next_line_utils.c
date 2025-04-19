/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:44:25 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/19 15:24:13 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	what;

	i = 0;
	what = 0;
	while (src[what] != '\0')
	{
		what++;
	}
	if (size == 0)
		return (what);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	return (what);
}

size_t	gnl_strlen(char const *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*gnl_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == (char)character)
			return ((char *)str);
		str++;
	}
	if (character == '\0' || *str == (char)character)
		return ((char *)str);
	return (NULL);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	strlens;

	if (s == NULL)
		return (NULL);
	strlens = gnl_strlen(s);
	if (start >= strlens)
		return (gnl_strdup(""));
	if (len > strlens - start)
		len = strlens - start;
	sub = malloc((sizeof(char)) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*gnl_strdup(const char *s1)
{
	size_t	i;
	char	*pimp;

	i = gnl_strlen(s1) + 1;
	pimp = (char *)malloc(i);
	if (pimp == NULL)
		return (NULL);
	gnl_strlcpy(pimp, s1, i);
	pimp[i - 1] = '\0';
	return (pimp);
}
