/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:00:19 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/18 21:07:12 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIDTH 400
#define HEIGHT 400

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error_rd();
	init_game_state(&game);
	game.filename = ft_strdup(av[1]);
	if (!game.filename)
		error_exit(&game, "Memory allocation failed");
	parse_map(&game, av[1]);
	game.mlx = mlx_init(game.map_width * TILE_SIZE, game.map_height * TILE_SIZE,
			"so_long", false);
	if (!game.mlx)
		error_exit(&game, "MLX initialization failed");
	game.wmage = mlx_new_image(game.mlx, game.map_width * TILE_SIZE,
			game.map_height * TILE_SIZE);
	if (!game.wmage)
		error_exit(&game, "Image creation failed");
	mlx_image_to_window(game.mlx, game.wmage, 0, 0);
	render_map(&game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
