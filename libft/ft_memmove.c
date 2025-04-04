/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:35:04 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/22 22:43:16 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (len == 0 || dst == src || (dst == NULL && src == NULL))
		return (dst);
	if (d < s || d >= (s + len))
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d = d + len;
		s = s + len;
		while (len--)
		{
			*(--d) = *(--s);
		}
	}
	return (dst);
}
