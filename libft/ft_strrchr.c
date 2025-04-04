/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:37:48 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/18 20:01:09 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	if (c == '\0')
		return ((char *)(s + n));
	while (n >= 0)
	{
		if (s[n] == (char)c)
			return ((char *)s + n);
		n--;
	}
	return (NULL);
}
//cast char * to null