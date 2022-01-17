/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:18:05 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/25 17:22:18 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	valid_exit(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	game_clear(void)
{
	write(1, "\033[93mYou Win!\033[0m\n", 18);
	exit(EXIT_SUCCESS);
}

static void	player_location(t_map *map, int x, int y)
{
	if (x >= 0 && y >= 0 && x < map->height && y < map->width)
	{
		if (map->map[x][y] == 'E')
		{
			if (valid_exit(map))
				game_clear();
		}
		else if (map->map[x][y] == 'A')
		{
			write(1, "\033[0;31mGame Over\033[0m\n", 21);
			exit(EXIT_SUCCESS);
		}
		else if (map->map[x][y] != '1')
		{
			map->map[map->x][map->y] = '0';
			map->x = x;
			map->y = y;
			map->map[x][y] = 'P';
			paint_map(&map->mlx, map, &map->img, "img/player2.xpm");
			map->step++;
		}
	}
}

int	key_press(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
	{
		write(1, "\033[0;36mYou Enter the ESC Key. Good Bye! :)\033[0m\n", 47);
		exit (EXIT_SUCCESS);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		player_location(map, map->x - 1, map->y);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		player_location(map, map->x + 1, map->y);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		player_location(map, map->x, map->y + 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		player_location(map, map->x, map->y - 1);
	enemy_location(map, map->enemy_x, map->enemy_y, keycode);
	return (0);
}

void	key_event(t_mlx *mlx, t_map *map)
{
	mlx_hook(mlx->win, X_EVENT_KEY_PRESS, 0, &key_press, map);
}
