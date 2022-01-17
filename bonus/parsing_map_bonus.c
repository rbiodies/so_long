/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:19:42 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/25 16:56:13 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	map_error(void)
{
	write(1, "Error\nInvalid Map\n", 18);
	exit(EXIT_FAILURE);
}

static int	check_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	size_t	width;
	int		height;

	fd = open(filename, O_DIRECTORY);
	if (fd > 0)
		map_error();
	fd = open(filename, O_RDONLY);
	if (fd < 0 || ft_strcmp(".ber", &filename[ft_strlen(filename) - 4]))
		map_error();
	line = get_next_line(fd);
	width = ft_strlen(line);
	height = 0;
	while (line)
	{
		if (width != ft_strlen(line))
			map_error();
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	map->height = height;
	return (width);
}

void	parsing_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	map->width = check_map(map, filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		map_error();
	map->map = (char **)malloc(sizeof(char *) * map->height);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	map->step = 0;
	valid_map(map);
}
