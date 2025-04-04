/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_xup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:09:46 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/08 20:32:01 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getin_hexi_nbr_up(unsigned int n, int fd)
{
	int		pos;
	int		count;
	char	*hex;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n == 0)
	{
		if (write(fd, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (n >= 16)
		count += getin_hexi_nbr_up(n / 16, fd);
	pos = n % 16;
	if (write(1, &hex[pos], 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	speci_xup(va_list things, int *count)
{
	unsigned int	u;
	int				frcount;

	u = va_arg(things, unsigned int);
	frcount = getin_hexi_nbr_up(u, 1);
	if (frcount < 0)
		return (-1);
	*count += frcount;
	return (0);
}
