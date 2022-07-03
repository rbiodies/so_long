/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:01:02 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/25 17:22:02 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/*****LIBRARIES*****/
# include "../libft/inc/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"

# include <fcntl.h> // open
# include <stdio.h> // perror
# include <time.h> // srand(time(NULL))

/*****BUFFER_SIZE*****/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*****STRUCTURES*****/
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*enemy;
	void	*collect;
	void	*road;
	void	*wall;
	void	*exit;
}	t_img;

typedef struct s_map {
	struct s_mlx	mlx;
	struct s_img	img;
	char			**map;
	int				width;
	int				height;
	int				x;
	int				y;
	int				empty;
	int				step;
	int				enemy_x;
	int				enemy_y;
	int				min_x;
	int				min_y;
}	t_map;

typedef struct s_check
{
	int	player;
	int	exit;
	int	collect;
}	t_check;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/*****KEYS_EVENT*****/
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define X_NO_EVENT_MASK 0
# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

/*****FUNCTIONS*****/
void	so_long(char *filename);
void	parsing_map(t_map *map, char *filename);
char	*get_next_line(int fd);
void	valid_map(t_map *map);
void	enemy(t_map *map);
void	*init_img_util(t_mlx *mlx, char *filename);
void	paint_map(t_mlx *mlx, t_map *map, t_img *img, char *player);
void	key_event(t_mlx *mlx, t_map *map);
void	enemy_location(t_map *map, int x, int y, int keycode);
int		player_loop(t_map *map);

#endif
