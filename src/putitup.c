/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putitup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:46:23 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/02 20:55:26 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// #define WIDTH 400
// #define HEIGHT 400

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	fill_image(mlx_image_t *img, uint32_t color)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while ((const uint32_t)y < img->height)
	{
		while ((const uint32_t)x < img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	init_mlx_objects(t_game *game)
{
	game->mlx = mlx_init(game->map_width * TILE_SIZE,
							game->map_height * TILE_SIZE,
							"Game",
							false);
	if (!game->mlx)
		error_exit(game, "MLX initialization failed");
	game->player = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	mlx_image_to_window(game->mlx, game->player, game->player_x,
			game->player_y);
	fill_image(game->player, 0xFF0000FF);
	game->floor = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	fill_image(game->floor, 0x333333FF);
	game->wall = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	fill_image(game->wall, 0xFFFFFFFF);
	game->goodie = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	fill_image(game->goodie, 0x0000FFFF);
	game->exit = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	fill_image(game->exit, 0xFFFF00FF);
}

void	render_tile(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	if (game->map[x][y] == '1')
		mlx_image_to_window(game->mlx, game->wall, px, py);
	else if (game->map[x][y] == '0')
		mlx_image_to_window(game->mlx, game->floor, px, py);
	else if (game->map[x][y] == 'P')
		mlx_image_to_window(game->mlx, game->player, px, py);
	else if (game->map[x][y] == 'C')
		mlx_image_to_window(game->mlx, game->goodie, px, py);
	else if (game->map[x][y] == 'E')
		mlx_image_to_window(game->mlx, game->exit, px, py);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	if (game->wall->count > 0)
	{
		mlx_delete_image(game->mlx, game->wall);
		mlx_delete_image(game->mlx, game->floor);
		mlx_delete_image(game->mlx, game->player);
		mlx_delete_image(game->mlx, game->goodie);
		mlx_delete_image(game->mlx, game->exit);
	}
	init_mlx_objects(game);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	mlx_set_instance_depth(game->player->instances, 1);
}
