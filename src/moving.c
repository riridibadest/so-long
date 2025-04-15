/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:22:10 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/15 18:01:37 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (game->game_won)
		{
			if (keydata.key == MLX_KEY_R)
				game->game_won = 0;
			return ;
		}
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_up(game);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_down(game);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_left(game);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_right(game);
	}
}

int	is_valid_move(t_game *g, int x, int y)
{
	if (x < 0 || x >= g->map_width)
		return (0);
	if (y < 0 || y >= g->map_height)
		return (0);
	return (g->map[y][x] != '1');
}

void	handle_move(t_game *g, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = g->player_x + dx;
	ny = g->player_y + dy;
	if (g->game_won || !is_valid_move(g, nx, ny))
		return;
	if (g->map[ny][nx] == 'E')
	{
		if (g->goodies == 0)
		{
			g->game_won = 1;
			show_end_screen(g);
		}
	}
	if (g->map[ny][nx] == 'C')
	{
		g->goodies--;
		g->map[ny][nx] = '0';
	}
	g->player_x = nx;  // Update player's x coordinate
	g->player_y = ny;  // Update player's y coordinate
	g->map[ny][nx] = 'P';  // Set new position to player
	// Render the updated map to reflect changes
	render_map(g);
	// Increment step counter
	g->talorswifeet++;
	// Update step counter display
	char *str = ft_itoa(g->talorswifeet);
	if (g->swifeetnbr)
		mlx_delete_image(g->mlx, g->swifeetnbr);
	g->swifeetnbr = mlx_put_string(g->mlx, str, 10, 10);
	free(str);
}

void	loop_feet(t_game *g)
{
	char	*str;

	g->talorswifeet++;
	render_map(g);
	mlx_delete_image(g->mlx, g->swifeetnbr);
	str = ft_itoa(g->talorswifeet);
	g->swifeetnbr = mlx_put_string(g->mlx, str, 10, 10);
	free(str);
}
