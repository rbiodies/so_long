/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:21:23 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/24 11:26:46 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	wall_error(void)
{
	write(1, "Error\nNo wall\n", 14);
	exit(EXIT_FAILURE);
}

void	game_error(void)
{
	write(1, "Error\nNo exit, collectible or player\n", 37);
	exit(EXIT_FAILURE);
}

void	check_char(t_check *check, char ch)
{
	if (ch != '1' && ch != 'C' && ch != 'E' && ch != 'P' && ch != 'A')
	{
		write(1, "Error\nUndefined character\n", 26);
		exit(EXIT_FAILURE);
	}
	else if (ch == 'P')
	{
		if (check->player == 1)
		{
			write(1, "Error\nToo many players\n", 23);
			exit(EXIT_FAILURE);
		}
		else
			check->player = 1;
	}
	else if (ch == 'C')
		check->collect = 1;
	else if (ch == 'E')
		check->exit = 1;
}

static void	player_place(t_map *map, int i, int j, char ch)
{
	if (ch == 'P')
	{
		map->x = i;
		map->y = j;
	}
	if (ch == '0')
		map->empty++;
}

void	valid_map(t_map *map)
{
	int		i;
	int		j;
	t_check	check;

	check = (t_check){0, 0, 0};
	map->empty = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (i == 0 || j == 0 || i == map->height - 1 || j == map->width - 1)
				if (map->map[i][j] != '1')
					wall_error();
			if (map->map[i][j] != '0')
				check_char(&check, map->map[i][j]);
			player_place(map, i, j, map->map[i][j]);
		}
	}
	if (check.collect == 0 || check.exit == 0 || check.player == 0)
		game_error();
	enemy(map);
}
