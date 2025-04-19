/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udlc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:19:19 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/18 21:07:26 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	move_up(t_game *map)
// {
// 	int	nx;
// 	int	ny;

// 	nx = map->player_x;
// 	ny = map->player_y - 1;
// 	handle_move(map, nx, ny);
// 	render_map(map);
// 	mlx_image_to_window(map->mlx, map->player, nx * TILE_SIZE, ny * TILE_SIZE);
// }

// void	move_down(t_game *map)
// {
// 	int	nx;
// 	int	ny;

// 	nx = map->player_x;
// 	ny = map->player_y + 1;
// 	handle_move(map, nx, ny);
// 	render_map(map);
// 	mlx_image_to_window(map->mlx, map->player, nx * TILE_SIZE, ny * TILE_SIZE);
// }

// void	move_left(t_game *map)
// {
// 	int	nx;
// 	int	ny;

// 	nx = map->player_x - 1;
// 	ny = map->player_y;
// 	handle_move(map, nx, ny);
// 	render_map(map);
// 	mlx_image_to_window(map->mlx, map->player, nx * TILE_SIZE, ny * TILE_SIZE);
// }

// void	move_right(t_game *map)
// {
// 	int	nx;
// 	int	ny;

// 	nx = map->player_x + 1;
// 	ny = map->player_y;
// 	handle_move(map, nx, ny);
// 	render_map(map);
// 	mlx_image_to_window(map->mlx, map->player, nx * TILE_SIZE, ny * TILE_SIZE);
// }

void	move_up(t_game *map)
{
	handle_move(map, 0, -1);
	if (map->game_won == 1)
		return ;
	render_map(map);
	loop_feet(map);
}

void	move_down(t_game *map)
{
	handle_move(map, 0, 1);
	if (map->game_won == 1)
		return ;
	render_map(map);
	loop_feet(map);
}

void	move_left(t_game *map)
{
	handle_move(map, -1, 0);
	if (map->game_won == 1)
		return ;
	render_map(map);
	loop_feet(map);
}

void	move_right(t_game *map)
{
	handle_move(map, 1, 0);
	if (map->game_won == 1)
		return ;
	render_map(map);
	loop_feet(map);
}
