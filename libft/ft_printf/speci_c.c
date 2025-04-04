/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:45:14 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/12 18:13:43 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void main()
// {
// 	int count;
// 	va_list red;

// 	count = 0;
// 	speci_c(red, &count);
// }

int	speci_c(va_list things, int *count)
{
	char	intake;

	intake = (char)va_arg(things, int);
	if (write(1, &intake, 1) == -1)
		return (-1);
	(*count)++;
	return (0);
}

// va_arg being cast with a character because it does not support char
//the function therefore it will take in an integer and convert into char.
//There is a range of integer that will represent the char
//if over the limit then it will loop within the number
//different format specifier will require the type to be different