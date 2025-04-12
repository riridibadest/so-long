/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boutdamap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:20:08 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/12 22:53:08 by yuerliu          ###   ########.fr       */
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
	game->mlx = NULL;
	game->uwin = NULL;
	printf("a\n");
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

// void	get_map_contents(t_game *g, const char *path)
// {
// 	int		fd;
// 	char	*line;
// 	int		y;

// 	fd = open(path, O_RDONLY);
// 	line = NULL;
// 	y = 0;
// 	if (fd < 0)
// 		error_exit(g, "Can't open map file");
// 	g->map = ft_calloc(g->map_height + 1, sizeof(char *));
// 	if (!g->map)
// 	{
// 		close(fd);
// 		error_exit(g, "Map allocation failed");
// 	}
// 	while (y < g->map_height)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		line[ft_strcspn(line, "\n")] = '\0';
// 		g->map[y] = ft_calloc(g->map_width + 1, sizeof(char));
// 		if (!g->map[y])
// 		{
// 			free(line);
// 			close(fd);
// 			error_exit(g, "Row allocation failed");
// 		}
// 		ft_strlcpy(g->map[y], line, g->map_width + 1);
// 		free(line);
// 		y++;
// 	}
// 	close(fd);
// 	if (y != g->map_height)
// 		error_exit(g, "Incomplete map data");
// 	if (ft_strlen(g->map[0]) != g->map_width)
// 		error_exit(g, "Map width mismatch");
// }

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
	fd = open(mapath, O_RDONLY);
	if (fd == -1)
		error_rd();
	while (pot->line)
	{
		pot->line = get_next_line(fd);
		if (pot->line == NULL)
			break ;
		pot->mapfile = ft_strjoin(pot->mapfile, pot->line);
		pot->line = NULL;
		if (!pot->mapfile)
			error_exit(pot, "Cant get map");
	}
	close(fd);
	pot->map = ft_split(pot->mapfile, '\n');
	if (!pot->map)
		error_exit(pot, "Cant save da map");
	pot->mapfile = NULL;
}

/* 
void	get_map_contents(t_game *pot, const char *map_path)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(map_path, O_RDONLY);
	line = NULL;
	y = 0;
	if (fd < 0)
		error_exit(pot, "Can't open map file");
	pot->map = ft_calloc(pot->map_height + 1, sizeof(char *));
	if (!pot->map)
	{
		close(fd);
		error_exit(pot, "Map allocation failed");
	}
	while (y < pot->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (ft_strchr(line, '\n'))
			line[ft_strcspn(line, "\n")] = '\0';
		pot->map[y] = ft_calloc(pot->map_width + 1, sizeof(char));
		if (!pot->map[y])
		{
			free(line);
			close(fd);
			error_exit(pot, "Row allocation failed");
		}
		ft_strlcpy(pot->map[y], line, pot->map_width + 1);
		free(line);
		y++;
	}
	close(fd);
	if (y != pot->map_height)
		error_exit(pot, "Incomplete map data");
}
*/
