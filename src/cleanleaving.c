/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanleaving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:00:09 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/02 22:24:17 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(t_game *game, const char *msg)
{
	clean_up(game, msg);
	ft_printf(RED "Error: %s\n" RESET, msg);
	exit(EXIT_FAILURE);
}

void	clean_up(t_game *game, const char *msg)
{
	int	y;

	if (!game)
		return ;
	if (game->map)
	{
		y = 0;
		while (game->map[y])
		{
			free(game->map[y]);
			y++;
		}
		free(game->map);
	}
	if (game->filename)
		free(game->filename);
	if (game->wmage)
		mlx_delete_image(game->mlx, game->wmage);
	if (game->mlx)
		mlx_terminate(game->mlx);
	ft_printf(RED "Error: %s\n" RESET, &msg);
}
