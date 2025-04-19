/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:40:21 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/18 21:07:42 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_end_screen(t_game *g)
{
	int		x;
	int		y;
	char	*str;

	x = (g->map_width * TILE_SIZE - g->uwin->width) / 2;
	y = (g->map_height * TILE_SIZE - g->uwin->height) / 2;
	if (!g->uwin)
		g->uwin = load_png(g, "pics/end.png");
	g->map[g->player_y][g->player_x] = 'P';
	render_end(g);
	mlx_image_to_window(g->mlx, g->uwin, x, y);
	str = "LETS TRIP";
	mlx_put_string(g->mlx, str, x, y);
	write(1, "\x1b[32;01m", 9);
	write(1, "🏆🏆 YOU WON!! 🏆🏆\n", 27);
	write(1, "\x1b[0m", 5);
}
// void	render_end(t_game *game)
// {
// 	int	y;
// 	int	x;

// 	if (!game->map)
// 		return ;
// 	y = 0;
// 	while (y < game->map_height)
// 	{
// 		x = 0;
// 		while (x < game->map_width)
// 		{
// 			mlx_image_to_window(game->mlx, game->floor, x * TILE_SIZE, y
// 				* TILE_SIZE);
// 			if (game->map[game->player_y][game->player_x] == 'P')
// 				mlx_image_to_window(game->mlx, game->uwin, x * TILE_SIZE, y
// 					* TILE_SIZE);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	render_end(t_game *game)
{
	int	y;
	int	x;
	int	px;
	int	py;

	if (!game->map)
		return ;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			px = x * TILE_SIZE;
			py = y * TILE_SIZE;
			mlx_image_to_window(game->mlx, game->trip, px, py);
			x++;
		}
		y++;
	}
}

// void	clean_pic(t_game *game)
// {
// 	if (game->player)
// 		mlx_delete_image(game->mlx, game->player);
// 	if (game->wall)
// 		mlx_delete_image(game->mlx, game->wall);
// 	if (game->floor)
// 		mlx_delete_image(game->mlx, game->floor);
// 	if (game->goodie)
// 		mlx_delete_image(game->mlx, game->goodie);
// 	if (game->exit)
// 		mlx_delete_image(game->mlx, game->exit);
// 	if (game->wmage)
// 		mlx_delete_image(game->mlx, game->wmage);
// 	game->player = NULL;
// 	game->wall = NULL;
// 	game->floor = NULL;
// 	game->goodie = NULL;
// 	game->exit = NULL;
// 	game->wmage = NULL;
// }
