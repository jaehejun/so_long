/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:18:11 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/17 22:58:17 by jaehejun         ###   ########.fr       */
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

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		column;
	int		row;
	int		player;
	int		escape;
	int		collectible;
}	t_map;

typedef struct s_image
{
	void	*desert_img;
	void	*wall_img;
	void	*player_img;
	void	*collectible_img;
	void	*escape_img;
}	t_image;

typedef struct s_game
{
	t_player	player;
	t_map		map;
	t_image		image;
	void		*mlx;
	void		*win;
}	t_game;

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
//void	check_valid_route(char **map, int row, int column,
//							int collectible, int escpae);

#endif
