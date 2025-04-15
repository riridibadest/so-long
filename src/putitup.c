/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putitup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:46:23 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/15 18:00:10 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// #define WIDTH 400
// #define HEIGHT 400

mlx_image_t	*load_png(t_game *game, char *path)
{
	mlx_texture_t	*pimp;
	mlx_image_t		*img;

	pimp = mlx_load_png(path);
	if (!pimp)
	{
		ft_putendl_fd("PNG load error", 2);
		exit(1);
	}
	img = mlx_texture_to_image(game->mlx, pimp);
	if (!img)
	{
		ft_putendl_fd("Failed to convert PNG to image", 2);
		exit(1);
	}
	mlx_delete_texture(pimp);
	return (img);
}

void	init_mlx_objects(t_game *game)
{
	game->player = load_png(game, "pics/riri.png");
	game->floor = load_png(game, "pics/land.png");
	game->wall = load_png(game, "pics/wall.png");
	game->goodie = load_png(game, "pics/shrum.png");
	game->exit = load_png(game, "pics/exit.png");
}

void	render_tile(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	if (!game->map)
	{
		printf("Error: map is NULL\n");
		return ;
	}
	if (!game->map[y])
	{
		printf("Error: map[%d] is NULL\n", y);
		return ;
	}
	if (game->map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->wall, px, py);
	else if (game->map[y][x] == '0')
		mlx_image_to_window(game->mlx, game->floor, px, py);
	else if (game->map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->player, px, py);
	else if (game->map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->goodie, px, py);
	else if (game->map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->exit, px, py);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	init_mlx_objects(game);
	// if (game->player->count > 0)
	// 	mlx_delete_image(game->mlx, game->player);
	// if (game->floor->count > 0)
	// 	mlx_delete_image(game->mlx, game->floor);
	// if (game->wall->count > 0)
	// 	mlx_delete_image(game->mlx, game->wall);
	// if (game->goodie->count > 0)
	// 	mlx_delete_image(game->mlx, game->goodie);
	// if (game->exit->count > 0)
	// 	mlx_delete_image(game->mlx, game->exit);
	// init_mlx_objects(game);
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
	mlx_set_instance_depth(game->player->instances, 10);
}
