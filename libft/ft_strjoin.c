/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:16:01 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/19 14:19:43 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_characters;
	char	*str_space;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_characters = ft_strlen(s1) + ft_strlen(s2);
	str_space = (char *)malloc((total_characters + 1) * sizeof(char));
	if (str_space == NULL)
		return (NULL);
	while (s1[i])
		str_space[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str_space[i++] = s2[j++];
	str_space[i] = '\0';
	return (str_space);
}
