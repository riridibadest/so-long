/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:19:27 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/23 16:56:59 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*pimp;

	i = ft_strlen(s1) + 1;
	pimp = (char *)malloc(i);
	if (pimp == NULL)
		return (NULL);
	ft_strlcpy(pimp, s1, i);
	pimp[i - 1] = '\0';
	return (pimp);
}
