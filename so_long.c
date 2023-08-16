/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:18:08 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/16 22:26:20 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"
#include <stdio.h>
#include <string.h>

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
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->background.img, game->player.x * 64, (game->player.y + 1) * 64);
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img, game->player.x * 64, game->player.y * 64);
			actual_move++;
		}
	}
	//down
	if (keycode == 125)
	{
		if (game->player.y < 1024 / 64 - 1)
		{
			(game->player.y++);
			printf("%d\n", game->player.y);
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->background.img, game->player.x * 64, (game->player.y - 1) * 64);
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img, game->player.x * 64, game->player.y * 64);
			actual_move++;
		}
	}
	//right
	if (keycode == 124)
	{
		if (game->player.x < 1920 / 64 - 1)
		{
			(game->player.x++);
			printf("%d\n", game->player.x);
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->background.img, (game->player.x - 1) * 64, game->player.y * 64);
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img, game->player.x * 64, game->player.y * 64);
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
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->background.img, (game->player.x + 1) * 64, game->player.y * 64);
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img, game->player.x * 64, game->player.y * 64);
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


int	main(int argc, char **argv)
{

	t_game	game;
	t_map	map;
	void	*mlx;
	void	*mlx_win;
	void	*tiles;
	int		img_width;
	int		img_height;
	
	int	x;
	int	y;
	x = 0;
	y = 0;
	
	char	*line = strdup("");
	char	*temp;
	int	fd;
	if (argc != 2)
	{
		printf("Error\n");
		exit (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		exit (1);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		temp = ft_strjoin(temp, line);
	}
	printf("TEMP : \n%s\n", temp);
	map.map = ft_split(temp, '\n');
	map.row = count_single(temp, '\n');
	map.column = ft_strlen(map.map[0]);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map.column * 64, map.row * 64, "so_long");
	tiles = mlx_xpm_file_to_image(mlx, "./desert.xpm", &img_width, &img_height);
	game.player.img = mlx_xpm_file_to_image(mlx, "./player.xpm", &img_width, &img_height);
	game.mlx = mlx;
	game.mlx_win = mlx_win;
	game.player.x = 3;
	game.player.y = 3;
	game.background.img = tiles;
	
	mlx_key_hook(mlx_win, key_hook, &game); // up array press event

	while (y < map.row)
	{
		while (x < map.column)
		{
			mlx_put_image_to_window(mlx, mlx_win, tiles, x++ * 64, y * 64);
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(mlx, mlx_win, game.player.img, game.player.x * 64, game.player.y * 64);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 0);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 64);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 128);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 192);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 256);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 320);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 384);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 448);
	

	
	
	//mlx_put_image_to_window(mlx, mlx_win, sprite, 0, 448);
	//mlx_put_image_to_window(mlx, mlx_win, player.img, 0, 448);
	
	
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 0);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 64);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 128);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 192);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 256);
	
	
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 320);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 384);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 448);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 0);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 64);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 128);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 192);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 256);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 320);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 384);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 448);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 0);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 64);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 128);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 192);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 256);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 320);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 384);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 448);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 0);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 64);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 128);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 192);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 256);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 320);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 384);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 448);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 0);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 64);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 128);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 192);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 256);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 320);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 384);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 448);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 0);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 64);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 128);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 192);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 256);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 320);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 384);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 448);
	
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 0);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 64);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 128);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 192);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 256);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 320);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 384);
	//mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 448);
	
	
	mlx_loop(mlx);
	return (0);
}
