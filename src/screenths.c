/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:40:21 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/02 21:01:55 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_end_screen(t_game *game)
{
	mlx_image_t	*overlay;
	xpm_t		*end_tex;
	size_t		gw;
	size_t		gh;

	if (game->uwin)
		mlx_delete_image(game->mlx, game->uwin);
	overlay = mlx_new_image(game->mlx, game->map_width, game->map_height);
	if (!overlay)
		return ;
	fill_image(overlay, ft_pixel(0, 0, 0, 200));
	mlx_image_to_window(game->mlx, overlay, 0, 0);
	mlx_set_instance_depth(overlay->instances, INT_MAX - 1);
	end_tex = mlx_load_xpm42("textures/ui/end_screen.xpm42");
	if (!end_tex)
		return ;
	game->uwin = mlx_texture_to_image(game->mlx, &end_tex->texture);
	mlx_delete_xpm42(end_tex);
	gw = (game->map_width - game->uwin->width) / 2;
	gh = (game->map_height - game->uwin->height) / 2;
	mlx_image_to_window(game->mlx, game->uwin, gw, gh);
	mlx_set_instance_depth(game->uwin->instances, INT_MAX);
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
