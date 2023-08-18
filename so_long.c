/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:18:08 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/18 22:14:44 by jaehejun         ###   ########.fr       */
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
		 if (game->player.y > 1 && game->map.map[game->player.y - 1][game->player.x] != '1')
		{
			(game->player.y--);
			mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, game->player.x * 64, (game->player.y + 1) * 64);
			if (game->map.map[game->player.y][game->player.x] != 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, game->player.x * 64, game->player.y * 64);
			mlx_put_image_to_window(game->mlx, game->win, game->image.player_img, game->player.x * 64, game->player.y * 64);
			actual_move++;
			if (game->map.map[game->player.y][game->player.x] == 'C')
				game->map.collectible--;
			if (game->map.map[game->player.y][game->player.x] == 'E' && game->map.collectible == 0)
			{
				printf("Movements: %d\n", movements);
				exit(0);
			}
		}
	}
	//down
	if (keycode == 125)
	{
		if (game->player.y < game->map.row - 2 && game->map.map[game->player.y + 1][game->player.x] != '1')
		{
			(game->player.y++);
			mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, game->player.x * 64, (game->player.y - 1) * 64);
			if (game->map.map[game->player.y][game->player.x] != 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, game->player.x * 64, game->player.y * 64);
			mlx_put_image_to_window(game->mlx, game->win, game->image.player_img, game->player.x * 64, game->player.y * 64);
			actual_move++;
			if (game->map.map[game->player.y][game->player.x] == 'C')
				game->map.collectible--;
			if (game->map.map[game->player.y][game->player.x] == 'E' && game->map.collectible == 0)
			{
				printf("Movements: %d\n", movements);
				exit(0);
			}
		}
	}
	//right
	if (keycode == 124)
	{
		if (game->player.x < game->map.column - 2 && game->map.map[game->player.y][game->player.x + 1] != '1')
		{
			(game->player.x++);
			mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, (game->player.x - 1) * 64, game->player.y * 64);
			if (game->map.map[game->player.y][game->player.x] != 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, game->player.x * 64, game->player.y * 64);
			mlx_put_image_to_window(game->mlx, game->win, game->image.player_img, game->player.x * 64, game->player.y * 64);
			actual_move++;
			if (game->map.map[game->player.y][game->player.x] == 'C')
				game->map.collectible--;
			if (game->map.map[game->player.y][game->player.x] == 'E' && game->map.collectible == 0)
			{
				printf("Movements: %d\n", movements);
				exit(0);
			}
		}
	}
	//left
	if (keycode == 123)
	{
		if (game->player.x > 1 && game->map.map[game->player.y][game->player.x - 1] != '1')
		{
			(game->player.x--);
			mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, (game->player.x + 1) * 64, game->player.y * 64);
			if (game->map.map[game->player.y][game->player.x] != 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->image.desert_img, game->player.x * 64, game->player.y * 64);
			mlx_put_image_to_window(game->mlx, game->win, game->image.player_img, game->player.x * 64, game->player.y * 64);
			actual_move++;
			if (game->map.map[game->player.y][game->player.x] == 'C')
				game->map.collectible--;
			if (game->map.map[game->player.y][game->player.x] == 'E' && game->map.collectible == 0)
			{
				printf("Movements: %d\n", movements);
				exit(0);
			}
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
	int		index;

	index = 0;
	while (temp[index] != '\0')
	{
		if (temp[index] == 'C')
			game->map.collectible++;
		else if (temp[index] == 'E')
			game->map.escape++;
		else if (temp[index] == 'P')
			game->map.player++;
		else if (temp[index] == '0' || temp[index == '1'] || temp[index] == '\n')
			;
		else
		{
			write(2, "Error : Invalid component exists!\n", 34);
			exit (1);
		}
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
	if (game->map.collectible < 1)
	{
		write(2, "Error : Collectible must be one at least\n", 42);
		exit (1);
	}
}

void	check_is_valid_rectangle(t_game *game)
{
	char	**map;
	int		column_count;

	map = game->map.map;
	column_count = 0;
	while (map[game->map.row] != NULL)
	{
		while (map[game->map.row][column_count] != '\0')
			column_count++;
		if (game->map.row == 0)
			game->map.column = column_count;
		if (game->map.column != column_count)
		{
			write(2, "Error : Map is not rectangular!\n", 32);
			exit (1);
		}
		game->map.row++;
		column_count = 0;
	}
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
					write(2, "Error : Map is not surrounded by walls!\n", 50);
					exit (1);
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
}

//void	check_valid_route(t_game *game)
//{
//	(void)game;
//}

void	check_map(char *argv, t_game *game)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error : Fail to open map file\n", 29);
		exit (1);
	}
	line = ft_strdup("");
	temp = ft_strdup("");
	while (line != NULL)
	{
		line = get_next_line(fd);
		temp = ft_strjoin(temp, line);
	}
	check_newline(temp);
	check_component(temp, game);
	game->map.map = ft_split(temp, '\n');
	check_is_valid_rectangle(game);
	check_component_number(game);
	is_surrounded_by_wall(game);
	//check_valid_route(game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		img_width;
	int		img_height;
	int	x = 0;
	int	y = 0;
	
	game.map.collectible = 0;
	printf("%d\n", game.map.collectible);
	printf("%d\n", game.map.escape);
	printf("%d\n", game.map.player);
	check_argument(argc, argv);
	check_map(argv[1], &game);
	
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.column * 64, game.map.row * 64, "so_long");
	game.image.desert_img = mlx_xpm_file_to_image(game.mlx, "./desert.xpm", &img_width, &img_height);
	game.image.player_img = mlx_xpm_file_to_image(game.mlx, "./player.xpm", &img_width, &img_height);
	game.image.wall_img = mlx_xpm_file_to_image(game.mlx, "./wall.xpm", &img_width, &img_height);
	game.image.collectible_img = mlx_xpm_file_to_image(game.mlx, "./spice.xpm", &img_width, &img_height);
	game.image.escape_img = mlx_xpm_file_to_image(game.mlx, "./escape.xpm", &img_width, &img_height);

	while (game.map.map[y] != NULL)
	{
		while (game.map.map[y][x] != '\0')
		{
			if (game.map.map[y][x] == 'P')
			{
				game.player.x = x;
				game.player.y = y;
			}
			x++;
		}
		y++;
		x = 0;
	}

	x = 0;
	y = 0;
	
	while (game.map.map[y] != NULL)
	{
		while (game.map.map[y][x] != '\0')
		{
			mlx_put_image_to_window(game.mlx, game.win, game.image.desert_img, x * 64, y * 64);
			if (game.map.map[y][x] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.image.player_img, x * 64, y * 64);
			else if (game.map.map[y][x] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.image.wall_img, x * 64, y * 64);
			else if (game.map.map[y][x] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.image.collectible_img, x * 64, y * 64);
			else if (game.map.map[y][x] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.image.escape_img, x * 64, y * 64);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_key_hook(game.win, key_hook, &game); // up array press event
	mlx_loop(game.mlx);
	return (0);
}
