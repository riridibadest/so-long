/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:16:01 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/09 21:40:07 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = s1 ? ft_strlen(s1) : 0;
	len2 = s2 ? ft_strlen(s2) : 0;
	new = (char *)malloc((sizeof(char)) * (len1 + len2 + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1 != '\0')
			new[i++] = *s1++;
	if (s2)
		while (*s2 != '\0')
			new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}
