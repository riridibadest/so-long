/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udlc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:19:19 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/02 00:11:19 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	move_up(t_game *map)
{
	handle_move(map, 0, -1);
}

void	move_down(t_game *map)
{
	handle_move(map, 0, 1);
}

void	move_left(t_game *map)
{
	handle_move(map, -1, 0);
}

void	move_right(t_game *map)
{
	handle_move(map, 1, 0);
}

