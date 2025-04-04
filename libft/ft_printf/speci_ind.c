/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_ind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:06:10 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/12 20:23:21 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	c;
	int		cnt;

	cnt = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		cnt++;
	}
	if (n >= 10)
		cnt += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	cnt++;
	return (cnt);
}

int	speci_ind(va_list things, int *count)
{
	int	nbr;
	int	frcount;

	nbr = va_arg(things, int);
	if (nbr == 0)
	{
		write(1, "0", 1);
		*count += 1;
		return (0);
	}
	if (!nbr)
		return (-1);
	frcount = ft_putnbr(nbr);
	*count += frcount;
	return (0);
}
