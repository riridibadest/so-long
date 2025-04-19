/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:37:08 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/18 19:15:24 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_rd(void)
{
	ft_printf(RED "Not A Right .ber Bruh" RESET "\n");
	exit(EXIT_FAILURE);
}

void	error_wall(void)
{
	ft_printf(RED "Error: Wall Leaking Bruh" RESET "\n");
	exit(EXIT_FAILURE);
}

void	error_shape(void)
{
	ft_printf(RED "Error: Not a Rectangle Bruh" RESET "\n");
	exit(EXIT_FAILURE);
}

void	error_badmap(void)
{
	ft_printf(RED "Error: Invalid Map Bruh" RESET "\n");
	exit(EXIT_FAILURE);
}

void	error_content(void)
{
	ft_printf(RED "Error: Whats In Da Map Bruh" RESET "\n");
	exit(EXIT_FAILURE);
}
