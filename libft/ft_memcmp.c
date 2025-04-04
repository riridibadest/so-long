/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:28:29 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/24 20:11:57 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				c;
	unsigned const char	*rpl1;
	unsigned const char	*rpl2;

	rpl1 = (unsigned const char *)s1;
	rpl2 = (unsigned const char *)s2;
	c = 0;
	while (c < n)
	{
		if (rpl1[c] != rpl2[c])
			return (rpl1[c] - rpl2[c]);
		c++;
	}
	return (0);
}
