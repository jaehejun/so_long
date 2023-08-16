/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:18:11 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/16 21:48:13 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "./mlx/mlx.h"



# define BUFFER_SIZE 100

typedef struct	s_player
{
	int	x;
	int	y;
	void	*img;
}	t_player;

typedef struct	s_map
{
	char	**map;
	int		row;
	int		column;
	int		collectible;
	int		escape;
}	t_map;

typedef struct	s_wall
{
	void	*wall_img;
}	t_wall;

typedef struct	s_collectible
{
	int	x;
	int	y;
	void	*collectible_img;
}	t_collectible;

typedef struct s_game
{
	t_player	player;
	t_player	background;
	t_map		map;
	t_wall		wall;
	void	*mlx;
	void	*mlx_win;
}	t_game;

//typedef struct	s_data
//{
//	void	*img;
//	void	*addr;
//	int		bit_per_pixel;
//	int		line_length;
//	int		endian;
//}	t_data;

//typedef struct	s_vars{
//	void	*mlx;
//	void	*win;
//}				t_vars;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

char	*free_memory(char *allocated1, char *allocated2);
char	*get_next_line(int fd);
char	*read_line(int fd, char *remain);
char	*make_line(char *temp_read);
char	*make_remain(char *temp_read);

int		count_single(const char *s, char c);
char	*single(const char *s, char c);
void	free_all(char **str, int index);
char	**ft_split(char const *s, char c);

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//int		close_win(int keycode, t_vars *vars);
void	check_valid_route(char **map, int row, int column, int collectible, int escpae);

#endif
