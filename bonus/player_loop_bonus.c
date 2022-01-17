/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_loop_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:20:20 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/25 13:21:28 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	player1(t_map *map, int flag)
{
	paint_map(&map->mlx, map, &map->img, "img/player1.xpm");
	flag++;
	return (flag);
}

int	player_loop(t_map *map)
{
	static int	flag;

	if (flag < 10)
	{
		map->img.collect = init_img_util(&map->mlx, "img/collect1.xpm");
		flag = player1(map, flag);
	}
	else if (flag < 20)
	{
		paint_map(&map->mlx, map, &map->img, "img/player3.xpm");
		flag++;
	}
	else if (flag < 30)
	{
		map->img.collect = init_img_util(&map->mlx, "img/collect2.xpm");
		flag = player1(map, flag);
	}
	else if (flag < 40)
	{
		paint_map(&map->mlx, map, &map->img, "img/player2.xpm");
		flag++;
	}
	else
		flag = 0;
	return (0);
}
