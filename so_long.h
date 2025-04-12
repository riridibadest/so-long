/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:18:37 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/12 22:56:28 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define TILE_SIZE 64

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*wmage;
	mlx_image_t	*player;
	mlx_image_t	*goodie;
	mlx_image_t	*exit;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*swifeetnbr;
	mlx_image_t	*uwin;
	char		*filename;
	char		*mapfile;
	char		**map;
	char		*line;
	int			player_x;
	int			player_y;
	int			bodycount;
	int			talorswifeet;
	int			goodies;
	int			exits;
	int			score;
	int			game_won;
	int			map_width;
	int			map_height;
}				t_game;

void			key_hook(mlx_key_data_t keydata, void *param);
void			init_game_state(t_game *game);
void			read_map_dimensions(t_game *pot, const char *map_path);
void			parse_map(t_game *game, const char *map_path);
void			rdnget_map(t_game *pot, const char *mapath);
void			falnem(t_game *name);
void			check_existence(t_game *pot);
void			check_walls(t_game *pot);
void			check_content(t_game *pot);
void			clean_up(t_game *game, const char *msg);
void			error_exit(t_game *game, const char *msg);
void			error_rd(void);
void			error_wall(void);
void			error_shape(void);
void			error_badmap(void);
void			error_content(void);
void			key_hook(mlx_key_data_t keydata, void *param);
int				is_valid_move(t_game *g, int x, int y);
void			handle_move(t_game *g, int dx, int dy);
void			loop_feet(t_game *g);
int32_t			ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void			fill_image(mlx_image_t *img, uint32_t color);
void			init_mlx_objects(t_game *game);
void			render_tile(t_game *game, int x, int y);
void			render_map(t_game *game);
void			show_end_screen(t_game *game);
void			end_screen_input(t_game *g);
void			move_up(t_game *map);
void			move_down(t_game *map);
void			move_left(t_game *map);
void			move_right(t_game *map);

// void			get_map_contents(t_game *pot, const char *map_path);

#endif