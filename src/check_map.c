/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:55:23 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/14 15:05:24 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	falnem(t_game *name)
{
	size_t	l;
	char	*ext;

	if (!name->filename)
		error_rd();
	l = ft_strlen(name->filename);
	if (l < 5)
		error_rd();
	ext = ft_substr(name->filename, l - 4, 4);
	if (!ext || ft_strncmp(ext, ".ber", 4) != 0)
	{
		free(ext);
		error_rd();
	}
	free(ext);
}

void	check_existence(t_game *pot)
{
	size_t	row_1;
	size_t	row_now;

	if (!pot->map || !pot->map[0])
		error_badmap();
	row_1 = ft_strlen(pot->map[0]);
	if (row_1 < 3)
		error_badmap();
	row_now = 1;
	while (pot->map[row_now])
	{
		if (ft_strlen(pot->map[row_now]) != row_1)
			error_shape();
		row_now++;
	}
}

void	check_walls(t_game *pot)
{
	int	x;
	int	y;

	if (!pot->map)
		return ;
	y = 0;
	while (y < pot->map_height)
	{
		if (!pot->map[y])
			return ;
		x = 0;
		while (x < pot->map_width)
		{
			if ((y == pot->map_height - 1) && pot->map[y][x] != '1')
				error_wall();
			if ((x == pot->map_width - 1) && pot->map[y][x] != '1')
				error_wall();
			x++;
		}
		y++;
	}
}

void	check_content(t_game *pot)
{
	int	x;
	int	y;

	if (!pot->map)
	{
		printf("-----------cc1--------------\n");
		error_badmap();
	}
	y = -1;
	while (++y < pot->map_height)
	{
		if (!pot->map[y])
			return ;
		x = -1;
		while (++x < pot->map_width)
		{
			if (!ft_strchr("01CEP", pot->map[y][x]))
				error_content();
			else if (pot->map[y][x] == 'P')
			{
				pot->player_x = x;
				pot->player_y = y;
				pot->bodycount++;
			}
			else if (pot->map[y][x] == 'E')
				pot->exits++;
			else if (pot->map[y][x] == 'C')
			{
				pot->goodies++;
				printf("%d\n", pot->goodies);
			}
		}
	}
	if (pot->bodycount != 1 || pot->exits != 1 || pot->goodies < 1)
		error_content();
}
