/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:29:27 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/25 17:21:53 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	game_over(void)
{
	write(1, "\033[0;31mGame Over\033[0m\n", 21);
	exit(EXIT_SUCCESS);
}

void	enemy_location(t_map *map, int x, int y, int keycode)
{
	if (keycode == KEY_D || keycode == KEY_RIGHT \
	|| keycode == KEY_A || keycode == KEY_LEFT)
	{
		if (y > map->y)
			y--;
		else if (y < map->y)
			y++;
	}
	else
	{
		if (x > map->x)
			x--;
		else if (x < map->x)
			x++;
	}
	if (map->map[x][y] == 'P')
		game_over();
	else if (map->map[x][y] == '0')
	{
		map->map[map->enemy_x][map->enemy_y] = '0';
		map->enemy_x = x;
		map->enemy_y = y;
		map->map[x][y] = 'A';
	}
}

void	enemy(t_map *map)
{
	int	enemy_count;

	enemy_count = 2;
	if (map->empty < enemy_count)
	{
		write(1, "Error\nToo many enemy patrols\n", 29);
		exit(EXIT_FAILURE);
	}
	while (enemy_count != 0)
	{
		srand(time(NULL));
		while (1)
		{
			map->enemy_x = rand() % map->height;
			map->enemy_y = rand() % map->width;
			if (map->map[map->enemy_x][map->enemy_y] == '0')
			{
				map->map[map->enemy_x][map->enemy_y] = 'A';
				break ;
			}
		}
		enemy_count--;
	}
}
