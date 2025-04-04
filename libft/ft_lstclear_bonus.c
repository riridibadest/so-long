/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:22:24 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/25 18:29:39 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*delete;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		delete = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = delete;
	}
	*lst = (NULL);
}
