/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:59:39 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/23 15:28:21 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (ft_strlen(dest) >= size)
		return (ft_strlen(src) + size);
	while (dest[i] && i < size)
	{
		i++;
	}
	while (src[n] && (i + n + 1) < (size))
	{
		dest[i + n] = src[n];
		n++;
	}
	if (i < size)
		dest[i + n] = '\0';
	return (ft_strlen(src) + i);
}
/*
int	main(void)
{
	int		i;
	int		j;
	char	s[];
	char	d[50];

	s[] = "FKING";
	d[50] = "man, hell";
	i = ft_strlcat(d, s, 10);
	printf("%d , %s\n", i, d);
	j = strlcat(d, s, 10);
	printf("%d\n", j);
}
*/
