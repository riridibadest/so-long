/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:01:21 by yuerliu           #+#    #+#             */
/*   Updated: 2025/03/17 20:16:33 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"

int	ft_printf(const char *fmt, ...);
int	check_speci(const char fmt, va_list things, int *count);
int	speci_c(va_list things, int *count);
int	speci_ind(va_list things, int *count);
int	speci_p(va_list things, int *count);
int	speci_s(va_list things, int *count);
int	speci_u(va_list things, int *count);
int	speci_x(va_list things, int *count);
int	speci_xup(va_list things, int *count);

#endif