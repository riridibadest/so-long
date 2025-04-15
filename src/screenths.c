/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:40:21 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/15 17:50:48 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_end_screen(t_game *game)
{
	mlx_image_t	*overlay;
	xpm_t		*end_tex;
	size_t		gw;
	size_t		gh;

	// gw = WINDOW_WIDTH * TILE_SIZE;
	// gh = WINDOW_HEIGHT * TILE_SIZE;
	// overlay = mlx_new_image(game->mlx, gw, gh);
	// if (!overlay)
	// 	return ;
	// fill_image(overlay, 0x0000007F);
	// mlx_image_to_window(game->mlx, overlay, 0, 0);
	// mlx_set_instance_depth(overlay->instances, INT_MAX - 1);
	// ft_printf("\n\nPress ESC to exit or R to play again\n\n");
	// game->game_won = 0;
	write(1, "\x1b[32;01m", 9);
	write(1, "🏆🏆YOU WON!!🏆🏆\n", 27);
	write(1, "\x1b[0m", 5);
}

void	end_screen_input(t_game	*g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
	else if (mlx_is_key_down(g->mlx, MLX_KEY_R))
	{
		parse_map(g, g->filename);
		render_map(g);
	}
}
