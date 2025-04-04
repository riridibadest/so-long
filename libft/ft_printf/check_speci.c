/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_speci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:50:36 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/12 18:23:48 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_speci(const char fmt, va_list things, int *count)
{
	if (fmt == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		(*count)++;
		return (0);
	}
	if (fmt == 'c')
		return (speci_c(things, count));
	if (fmt == 'i' || fmt == 'd')
		return (speci_ind(things, count));
	if (fmt == 'p')
		return (speci_p(things, count));
	if (fmt == 's')
		return (speci_s(things, count));
	if (fmt == 'u')
		return (speci_u(things, count));
	if (fmt == 'x')
		return (speci_x(things, count));
	if (fmt == 'X')
		return (speci_xup(things, count));
	return (-1);
}
//idk if i will need sth to go through the whole fmt
// int	check_fmt(const char *fmt, va_list things, int count)
// {
// 	count = 0;
// 	while (fmt)
// 	{
// 		if (*fmt == '%')
// 		{
// 			write(1, '%', 1);
// 			count++;
// 		}
// 			*fmt++;
// 		}
// 		if (*fmt == "c")
// 			speci_c(things, count);

// 	}
// }

// int chech_n(const char *fmt, int *count)
// {
// 	if (*fmt == '%')
// 	{
// 		if (*fmt++ == '%')
// 		{
// 			write(1, '%', 1);
// 			*count++;
// 		}
// 		*fmt++;
// 	}
// 	return ()
// }

//can I not just roll through the string? and then have the count.
//or i might need to keep the count?
//have the count in main so i will get the correct number each time i count