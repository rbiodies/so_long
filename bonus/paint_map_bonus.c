/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:23:29 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/25 13:06:55 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	paint_background(t_mlx *mlx, t_map *map, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			mlx_put_image_to_window(\
			mlx->mlx, mlx->win, img->road, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	print_img(t_mlx *mlx, char *filename, int x, int y)
{
	void	*img;
	int		w;
	int		h;

	h = 0;
	w = 0;
	img = mlx_xpm_file_to_image(mlx->mlx, filename, &w, &h);
	if (h == 0 || w == 0)
	{
		write(1, "Error\n", 6);
		perror("img");
		exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
}

static void	put_string_mlx(t_map *map, t_mlx *mlx)
{
	char	*step;
	char	*paint;

	step = ft_itoa(map->step);
	paint = ft_strjoin("Steps: ", step);
	mlx_string_put(\
	mlx->mlx, mlx->win, map->width, map->height, 0x000000, paint);
	free(step);
	free(paint);
}

static void	set_img(t_mlx *mlx, t_img *img, t_point p, char ch)
{
	if (ch == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img->wall, p.x, p.y);
	if (ch == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img->collect, p.x, p.y);
	if (ch == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img->exit, p.x, p.y);
	if (ch == 'A')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img->enemy, p.x, p.y);
}

void	paint_map(t_mlx *mlx, t_map *map, t_img *img, char *player)
{
	int	i;
	int	j;

	paint_background(mlx, map, img);
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == '1')
				set_img(mlx, img, (t_point){j * 32, i * 32}, '1');
			else if (map->map[i][j] == 'C')
				set_img(mlx, img, (t_point){j * 32, i * 32}, 'C');
			else if (map->map[i][j] == 'E')
				set_img(mlx, img, (t_point){j * 32, i * 32}, 'E');
			else if (map->map[i][j] == 'A')
				set_img(mlx, img, (t_point){j * 32, i * 32}, 'A');
			else if (map->map[i][j] == 'P')
				print_img(mlx, player, j * 32, i * 32);
		}
	}
	put_string_mlx(map, mlx);
}
