/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:04:39 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/12 20:16:18 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	noneg_putnbr(unsigned int n, int fd)
{
	char	c;
	int		return_nb;

	return_nb = 0;
	if (n >= 10)
	{
		return_nb += noneg_putnbr(n / 10, fd);
	}
	c = (n % 10) + '0';
	if (write(fd, &c, 1) == -1)
		return (-1);
	return_nb++;
	return (return_nb);
}

int	speci_u(va_list things, int *count)
{
	unsigned int	u;
	int				frcount;

	u = (unsigned int)va_arg(things, unsigned int);
	if (u == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		*count += 1;
		return (0);
	}
	else if (u == (unsigned int)LONG_MIN)
	{
		if (write(1, "9223372036854775808", 19) == -1)
			return (-1);
		*count += 19;
		return (0);
	}
	if (!u)
		return (-1);
	frcount = noneg_putnbr(u, 1);
	if (frcount == -1)
		return (-1);
	*count += frcount;
	return (0);
}

// if (u == NULL)
// 	return (NULL); could add before if noneg.
	// if (u == 0)
	// {
	// 	write (1, "0", 1);
	// 	*count += 1;
	// 	return (0);
	// }
	//deleted from speciu function