/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanleaving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:00:09 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/15 17:50:46 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(t_game *game, const char *msg)
{
	char	*safe_msg;

	safe_msg = NULL;
	if (msg)
		safe_msg = ft_strdup(msg);
	clean_up(game, NULL);
	if (safe_msg)
		ft_printf(RED "Error: %s\n" RESET, safe_msg);
	else
		ft_printf(RED "Error: Unknown error\n" RESET);
	exit(EXIT_FAILURE);
}

void	clean_up(t_game *game, const char *msg)
{
	int	y;

	(void)msg;
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
}
