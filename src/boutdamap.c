/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boutdamap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:20:08 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/18 19:37:47 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_state(t_game *game)
{
	game->goodies = 0;
	game->exits = 0;
	game->bodycount = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->filename = NULL;
	game->map = NULL;
	game->line = NULL;
	game->mlx = NULL;
	game->uwin = NULL;
}

void	read_map_dimensions(t_game *pot, const char *map_path)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_rd();
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[--len] = '\0';
		if (len > (size_t)pot->map_width)
			pot->map_width = len;
		pot->map_height++;
		free(line);
	}
	close(fd);
	if (pot->map_width == 0 || pot->map_height == 0)
		error_badmap();
}

void	parse_map(t_game *game, const char *map_path)
{
	falnem(game);
	read_map_dimensions(game, map_path);
	rdnget_map(game, map_path);
	check_existence(game);
	check_walls(game);
	check_content(game);
}

void	rdnget_map(t_game *pot, const char *mapath)
{
	int		fd;

	pot->mapfile = NULL;
	pot->line = NULL;
	fd = open(mapath, O_RDONLY);
	if (fd == -1)
		error_rd();
	rdnget_help(pot, fd);
	close(fd);
	pot->map = ft_split(pot->mapfile, '\n');
	if (!pot->map)
		error_exit(pot, "Cant save da map");
	free(pot->mapfile);
	pot->mapfile = NULL;
}

void	rdnget_help(t_game *pot, int fd)
{
	size_t	len;
	char	*temp;

	while (1)
	{
		pot->line = get_next_line(fd);
		if (pot->line == NULL)
			break ;
		len = ft_strlen(pot->line);
		if (len > 0 && pot->line[len - 1] == '\n')
			pot->line[len - 1] = '\0';
		pot->mapfile = ft_strjoin(pot->mapfile, pot->line);
		free(pot->line);
		pot->line = NULL;
		if (pot->mapfile)
		{
			temp = pot->mapfile;
			pot->mapfile = ft_strjoin(temp, "\n");
			free(temp);
			if (!pot->mapfile)
				error_exit(pot, "Memory allocation failed");
		}
		else
			error_exit(pot, "Cant get map");
	}
}
