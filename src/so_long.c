/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:00:19 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/12 22:55:02 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIDTH 400
#define HEIGHT 400

// int	main(int ac, char **argv)
// {
// 	t_game	game;

// 	if (ac != 2)
// 		return (ft_printf("%s", "map file wrong"), EXIT_FAILURE);
// 	game.filename = ft_strdup(argv[1]);
// 	parse_map(&game, argv[1]);
// 	render_map(&game);
// 	mlx_key_hook(game.mlx, key_hook, &game);
// 	mlx_loop(game.mlx);
// 	mlx_terminate(game.mlx);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error_rd();
	printf("-----------1--------------\n");
	init_game_state(&game);
	printf("-----------2--------------\n");
	game.filename = ft_strdup(av[1]);
	printf("-----------3--------------\n");
	if (!game.filename)
	error_exit(&game, "Memory allocation failed");
	printf("-----------4--------------\n");
	parse_map(&game, av[1]);
	printf("-----------5--------------\n");
	game.mlx = mlx_init(game.map_width * TILE_SIZE, game.map_height * TILE_SIZE,
			"so_long", false);
	printf("-----------6-1-------------\n"); 
	if (!game.mlx)
		error_exit(&game, "MLX initialization failed");
	printf("-----------6--------------\n"); 
	game.wmage = mlx_new_image(game.mlx, game.map_width * TILE_SIZE,
			game.map_height * TILE_SIZE);
	if (!game.wmage)
		error_exit(&game, "Image creation failed");
	mlx_image_to_window(game.mlx, game.wmage, 0, 0);
	render_map(&game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	clean_up(&game, NULL);
	return (0);
}
