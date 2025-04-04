/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:04:21 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/23 16:29:50 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*prt;

	prt = (unsigned char *)s;
	while (n > 0)
	{
		if (*prt == (unsigned char)c)
			return ((void *)prt);
		prt++;
		n--;
	}
	return (NULL);
}
