/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:50:36 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/10 19:48:39 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getin_hexi_nbr(unsigned int n, int fd)
{
	int		pos;
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (n == 0)
	{
		if (write(fd, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (n >= 16)
		count += getin_hexi_nbr(n / 16, fd);
	pos = n % 16;
	if (write(1, &hex[pos], 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	speci_x(va_list things, int *count)
{
	unsigned int	u;
	int				frcount;

	u = va_arg(things, unsigned int);
	frcount = getin_hexi_nbr(u, 1);
	if (frcount < 0)
		return (-1);
	*count += frcount;
	return (0);
}
//give a string of 0 to f