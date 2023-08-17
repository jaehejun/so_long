/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:18:08 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/17 23:42:20 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"
#include <stdio.h>
#include <string.h>
# define TRUE 1
# define FALSE 0

// 키보드 입력 처리
int	key_hook(int keycode, t_game *game)
{
	static int	movements;
	int			actual_move;

	actual_move = 0;
	//up
	if (keycode == 126)
	{
		 if (game->player.y > 0)
		{
			(game->player.y--);
			printf("%d\n", game->player.y);
			mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, game->player.x * 64, (game->player.y + 1) * 64);
			mlx_put_image_to_window(game->mlx, game->win, game->image.player_img, game->player.x * 64, game->player.y * 64);
			actual_move++;
		}
	}
	//down
	if (keycode == 125)
	{
		if (game->player.y < game->map.row - 1)
		{
			(game->player.y++);
			printf("%d\n", game->player.y);
			mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, game->player.x * 64, (game->player.y - 1) * 64);
			mlx_put_image_to_window(game->mlx, game->win, game->image.player_img, game->player.x * 64, game->player.y * 64);
			actual_move++;
		}
	}
	//right
	if (keycode == 124)
	{
		if (game->player.x < game->map.column - 1)
		{
			(game->player.x++);
			printf("%d\n", game->player.x);
			mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, (game->player.x - 1) * 64, game->player.y * 64);
			mlx_put_image_to_window(game->mlx, game->win, game->image.player_img, game->player.x * 64, game->player.y * 64);
			actual_move++;
		}
	}
	//left
	if (keycode == 123)
	{
		if (game->player.x > 0)
		{
			(game->player.x--);
			printf("%d\n", game->player.x);
			mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, (game->player.x + 1) * 64, game->player.y * 64);
			mlx_put_image_to_window(game->mlx, game->win, game->image.player_img, game->player.x * 64, game->player.y * 64);
			actual_move++;
		}
	}
	if (keycode == 53)
		exit(0);
	if (actual_move == 1)
	{
		movements++;
		printf("Movements: %d\n", movements);
	}
	return (0);
}

int	check_ber(char *file, int len)
{
	if (len < 5)
		return (FALSE);
	if (file[len - 1] != 'r')
		return (FALSE);
	if (file[len - 2] != 'e')
		return (FALSE);
	if (file[len - 3] != 'b')
		return (FALSE);
	if (file[len - 4] != '.')
		return (FALSE);
	if (file[len - 5] == '/')
		return (FALSE);
	return (TRUE);
}

void check_argument(int argc, char **argv)
{
	int	file_len;

	file_len = ft_strlen(argv[1]);
	if (argc != 2)
	{
		write(2, "USAGE : ./so_long mapname.ber\n", 35);
		exit (1);
	}
	printf("%s\n", &argv[1][file_len - 4]);
	if (check_ber(argv[1], file_len) == FALSE)
	{
		write(2, "Error : Map format must be *.ber\n", 33);
		exit (1);
	}
}

void	check_newline(char *temp)
{
	int	index;
	int	temp_len;

	index = 0;
	temp_len = ft_strlen(temp);
	while (temp[index] != '\0')
	{
		if (temp[0] == '\n' || temp[temp_len -1] == '\n')
		{
			write(2, "Error : Map starts or ends with newline\n", 40);
			exit (1);
		}
		if (temp[temp_len] == '\n' && temp[temp_len + 1] == '\n')
		{
			write(2, "Error : Map has empty line\n", 27);
			exit (1);
		}
		index++;
	}
}

void	check_component(char *temp, t_game *game)
{
	int	index;
	
	index = 0;
	while (temp[index] != '\0')
	{
		if (temp[index] == 'P')
			game->map.player++;
		else if (temp[index] == 'E')
			game->map.escape++;
		else if (temp[index] == 'C')
			game->map.collectible++;
		else if (temp[index] == '1')
			;
		else if (temp[index] == '0')
			;
		else
			;
		//{
		//	write(2, "Error : Invalid component exists!\n", 34);
		//	exit (1);
		//}
		index++;
	}
}

void	check_component_number(t_game *game)
{
	if (game->map.player != 1)
	{
		write(2, "Error : Player must be one\n", 27);
		exit (1);
	}
	if (game->map.escape != 1)
	{
		write(2, "Error : Escape must be one\n", 27);
		exit (1);
	}
	if (game->map.collectible == 0)
	{
		write(2, "Error : Collectible must be one at least\n", 42);
		exit (1);
	}
}

void	check_is_valid_rectangle(t_game *game)
{
	char	**map;

	map = game->map.map;
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (map[row] != NULL)
	{
		while (map[row][column] != '\0')
			column++;
		if (row == 0)
			game->map.column = column;
		if (game->map.column != column)
		{
			write(2, "Error : Map is not rectangular!\n", 32);
			exit (1);
		}
		row++;
		column = 0;
	}
	game->map.row = row;
	if (game->map.column > 2560 / 64 || game->map.row > 1440 / 64)
	{
		write(2, "Error : Map size is too big\n", 28);
		exit (1);
	}
}

void	is_surrounded_by_wall(t_game *game)
{
	char	**map;
	int		y;
	int		x;
	
	map = game->map.map;
	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (y == 0 || y == (game->map.row - 1)\
			|| x == 0 || x == (game->map.column - 1))
			{
				if (map[y][x] != '1')
				{
					write(2, "Error : Map is not surrounded by walls!\n", 40);
					exit (1);
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	check_valid_route(t_game *game)
{
	(void)game;
}

void	check_map(char *argv, t_game *game)
{
	int		fd;
	char	*line;
	char	*temp;

	printf("CHECK_MAP START\n");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error : Fail to open map file\n", 29);
		exit (1);
	}
	printf("OPEN MAP FILE\n");
	line = ft_strdup("");
	temp = ft_strdup("");
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("GET_NEXT_LINE\n");
		temp = ft_strjoin(temp, line);
		printf("FT_STRJOIN\n");
	}
	printf("BEFORE CHECK MAP FUNCS\n");
	check_newline(temp);
	check_component(temp, game);
	check_component_number(game);
	game->map.map = ft_split(temp, '\n');
	check_is_valid_rectangle(game);
	is_surrounded_by_wall(game);
	check_valid_route(game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		img_width;
	int		img_height;
	int	x = 0;
	int	y = 0;
	
	check_argument(argc, argv);
	printf("CHECK_ARGUMENT DONE\n");
	check_map(argv[1], &game);
	printf("CHECK_MAP DONE\n");
	game.player.x = 0;
	game.player.y = 0;
	
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.column * 64, game.map.row * 64, "so_long");
	game.image.desert_img = mlx_xpm_file_to_image(game.mlx, "./desert.xpm", &img_width, &img_height);
	game.image.player_img = mlx_xpm_file_to_image(game.mlx, "./player.xpm", &img_width, &img_height);
	game.image.collectible_img = mlx_xpm_file_to_image(game.mlx, "./spice.xpm", &img_width, &img_height);
	game.image.escape_img = mlx_xpm_file_to_image(game.mlx, "./escape.xpm", &img_width, &img_height);

	mlx_key_hook(game.win, key_hook, &game); // up array press event

	while (y < game.map.row)
	{
		while (x < game.map.column)
		{
			mlx_put_image_to_window(game.mlx, game.win, game.image.desert_img, x++ * 64, y * 64);
		}
		y++;
		x = 0;
	}
	while (game.map.map[y] != NULL)
	{
		while (game.map.map[y][x] != '\0')
		{
			if (game.map.map[y][x] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.image.wall_img, x * 64, y * 64);
			else if (game.map.map[y][x] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.image.player_img, x * 64, y * 64);
			else if (game.map.map[y][x] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.image.collectible_img, x * 64, y * 64);
			else if (game.map.map[y][x] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.image.escape_img, x * 64, y * 64);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_loop(game.mlx);
	return (0);
}
