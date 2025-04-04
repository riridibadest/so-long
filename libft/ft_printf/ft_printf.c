/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:56 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/12 20:23:15 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format(const char **sth, va_list brothers, int *count)
{
	(*sth)++;
	if (check_speci(**sth, brothers, count) == -1)
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		(*count)++;
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		brothers;
	int			count;
	const char	*sth;

	sth = fmt;
	count = 0;
	va_start(brothers, fmt);
	while (*sth != '\0')
	{
		if (*sth == '%')
		{
			if (process_format(&sth, brothers, &count) == -1)
				return (va_end(brothers), -1);
		}
		else
		{
			if (write(1, sth, 1) == -1)
				return (va_end(brothers), -1);
			count++;
		}
		sth++;
	}
	va_end(brothers);
	return (count);
}

// int	ft_printf(const char *fmt, ...)
// {
// 	va_list		brothers;
// 	int			count;
// 	const char	*sth;

// 	sth = fmt;
// 	count = 0;
// 	va_start(brothers, fmt);
// 	while (*sth != '\0')
// 	{
// 		if (*sth == '%')
// 		{
// 			sth++;
// 			if (check_speci(*sth, brothers, &count) == -1)
// 			{
// 				if (write(1, "%", 1) == -1)
// 					return (va_end(brothers), -1);
// 				count++;
// 			}
// 		}
// 		else
// 		{
// 			if (write(1, sth, 1) == -1)
// 				return (va_end(brothers), -1);
// 			count++;
// 		}
// 		sth++;
// 	}
// 	va_end(brothers);
// 	return (count);
// }
// int main()
// {
// 	int i = printf("hello");

// 	printf("%d", i);
// }
// returning a value does nt mean it is printed out.;