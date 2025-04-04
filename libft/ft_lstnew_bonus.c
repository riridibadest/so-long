/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:19:39 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/25 17:50:12 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*idk;

	idk = (t_list *)malloc(sizeof(t_list));
	if (!idk)
		return (NULL);
	idk->content = content;
	idk->next = NULL;
	return (idk);
}
