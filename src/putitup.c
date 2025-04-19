/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putitup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:46:23 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/17 22:11:17 by yuerliu          ###   ########.fr       */
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
		exit(1);
	img = mlx_texture_to_image(game->mlx, pimp);
	if (!img)
		exit(1);
	mlx_delete_texture(pimp);
	if (img->width != TILE_SIZE || img->height != TILE_SIZE)
	{
		if (!mlx_resize_image(img, TILE_SIZE, TILE_SIZE))
		{
			ft_putendl_fd("Failed to resize image", 2);
			mlx_delete_image(game->mlx, img);
			exit(1);
		}
	}
	return (img);
}

void	init_mlx_objects(t_game *game)
{
	game->player = load_png(game, "pics/riri.png");
	game->floor = load_png(game, "pics/back.png");
	game->wall = load_png(game, "pics/path.png");
	game->goodie = load_png(game, "pics/shrum.png");
	game->exit = load_png(game, "pics/exit.png");
	game->uwin = load_png(game, "pics/end.png");
	game->trip = load_png(game, "pics/trip.png");
}

// void	render_tile(t_game *game, int x, int y)
// {
// 	int		px;
// 	int		py;
// 	char	type;

// 	px = x * TILE_SIZE;
// 	py = y * TILE_SIZE;
// 	printf("x: %d y: %d", x, y);
// 	if (!game->map)
// 		return ;
// 	if (game->map[y][x])
// 		type = game->map[y][x];
// 	else
// 		return ;
// 	if (type != '1'){
// 		if (!mlx_image_to_window(game->mlx, game->floor, px, py))
// 		{
// 			printf("htdfuytdu");
// 			printf("x: %d", x);
// 			printf("y: %d", y);
// 			if (!game->mlx)
// 				printf("game");
// 			if (!game->floor)
// 				printf("floor");
// 			exit(1);
// 		}
// 		printf("Background");
// 	}
// 	else
// 		mlx_image_to_window(game->mlx, game->wall, px, py);
// 	if (type == 'C'){
// 		if (!mlx_image_to_window(game->mlx, game->goodie, px, py))
// 			exit(2);
// 		printf("shroom");
// 	}
// 	// else if (type == 'P')
// 	// 	mlx_image_to_window(game->mlx, game->player, px, py);
// 	else if (type == 'E'){
// 		if (!mlx_image_to_window(game->mlx, game->exit, px, py))
// 			exit(3);
// 		printf("EXIT");
// 	}
// 	if (game->player_x == x && game->player_y == y){
// 		if (!mlx_image_to_window(game->mlx, game->player, px, py))
// 			exit(4);
// 		printf("Player");
// 	}
// }

void	render_tile(t_game *game, int x, int y)
{
	int		px;
	int		py;
	char	type;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	if (!game->map)
		return ;
	type = game->map[y][x];
	if (type != '1')
		mlx_image_to_window(game->mlx, game->floor, px, py);
	if (type == '1')
		mlx_image_to_window(game->mlx, game->wall, px, py);
	else if (type == 'C')
		mlx_image_to_window(game->mlx, game->goodie, px, py);
	else if (type == 'E')
		mlx_image_to_window(game->mlx, game->exit, px, py);
	else if (type == 'P')
		mlx_image_to_window(game->mlx, game->player, px, py);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

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
}
