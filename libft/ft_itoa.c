/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:50:25 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/24 20:17:39 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_reverse(char *s)
{
	int		begin;
	int		end;
	char	*reverse;
	char	holdplace;
	size_t	non;
	size_t	non;

	reverse = s;
	end = ft_strlen(reverse) - 1;
	begin = 0;
	if (s == NULL)
		return (NULL);
	while (begin < end)
	{
		holdplace = reverse[end];
		reverse[end] = reverse[begin];
		reverse[begin] = holdplace;
		begin++;
		end--;
	}
	return (reverse);
}*/
int	ft_count(int n)
{
	int	non;

	non = 0;
	if (n <= 0)
		non = 1;
	while (n != 0)
	{
		n = n / 10;
		non++;
	}
	return (non);
}

char	*ft_itoa(int n)
{
	char	*itc;
	size_t	length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = ft_count(n);
	itc = (char *)malloc((length + 1) * (sizeof(char)));
	if (itc == NULL)
		return (NULL);
	itc[length] = '\0';
	if (n == 0)
		itc[0] = '0';
	if (n < 0)
	{
		itc[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		itc[--length] = (n % 10) + '0';
		n = n / 10;
	}
	return (itc);
}
