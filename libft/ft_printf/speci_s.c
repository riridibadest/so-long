/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:10:02 by yuerliu           #+#    #+#             */
/*   Updated: 2024/11/12 18:35:43 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	speci_s(va_list things, int *count)
{
	char	*pt;

	pt = va_arg(things, char *);
	if (!pt)
		pt = "(null)";
	while (*pt != '\0')
	{
		if ((write(1, pt++, 1) == -1))
			return (-1);
		(*count)++;
	}
	return (0);
}
