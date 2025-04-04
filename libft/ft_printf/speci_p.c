/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:00:56 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/12 20:16:56 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getin_hexi_nbr(unsigned long n, int fd)
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

int	speci_p(va_list things, int *count)
{
	void	*i;
	int		frcount;
	int		temp;

	i = va_arg(things, void *);
	if (i == NULL)
	{
		temp = write(1, "0x0", 3);
		if (temp == -1)
			return (-1);
		*count += 3;
		return (0);
	}
	temp = write(1, "0x", 2);
	if (temp == -1)
		return (-1);
	*count += 2;
	frcount = getin_hexi_nbr((unsigned long)i, 1);
	if (frcount < 0)
		return (-1);
	*count += frcount;
	return (0);
}
