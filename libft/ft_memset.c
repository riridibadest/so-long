/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:58:42 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/21 19:01:18 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*i;
	size_t			n;

	i = (unsigned char *)b;
	n = 0;
	while (n < len)
	{
		i[n] = (unsigned char)c;
		n++;
	}
	return (i);
}
