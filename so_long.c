/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:18:08 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/15 23:29:16 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"
#include <stdio.h>

//int	main(void)
//{
//	void	*mlx;
//	void	*img;
//	char	*relative_path = "./desert.xpm";
//	int		img_width;
//	int		img_height;

//	mlx = mlx_init();
//	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
//	mlx_put_image_to_window(mlx, mlx_new_window(mlx, img_width, img_height, "so_long"), img, 0, 0);
//	mlx_loop(mlx);
//}



//int	render_next_frame(void *YourStruct);

//int	main(void)
//{
//	void	*mlx;

//	mlx = mlx_init();
//	mlx_loop_hook(mlx, render_next_frame, YourStruct);
//	mlx_loop(mlx);
//}


int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	(void)keycode;
	printf("Hello from key_hook!\n");
	return (0);
}

//int	main(void)
//{
//	t_vars	vars;

//	vars.mlx = mlx_init();
//	vars.mlx_win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
//	mlx_key_hook(vars.mlx_win, key_hook, &vars);
//	mlx_loop(vars.mlx);
//}








//typedef struct	s_data {
//	void	*img;
//	void	*addr;
//	int		bit_per_pixel;
//	int		line_length;
//	int		endian;
//}	t_data;

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;

//	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

//int	main(void)
//{
//	void	*mlx;
//	void	*mlx_win;
//	t_data	img;

//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
//	img.img = mlx_new_image(mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_length, &img.endian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//	my_mlx_pixel_put(&img, 10, 10, 0x0000FF00);
//	my_mlx_pixel_put(&img, 15, 15, 0x000000FF);
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_loop(mlx);
//}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*tiles;
	void	*player;
	void	*sprite;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	tiles = mlx_xpm_file_to_image(mlx, "./desert.xpm", &img_width, &img_height);
	player = mlx_xpm_file_to_image(mlx, "./player.xpm", &img_width, &img_height);
	sprite = mlx_xpm_file_to_image(mlx, "./sprite.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 64);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 128);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 192);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 256);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 320);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 384);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 0, 448);
	
	mlx_put_image_to_window(mlx, mlx_win, player, 16, 448);
	
	mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 0);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 64);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 128);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 192);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 256);
	
	mlx_put_image_to_window(mlx, mlx_win, sprite, 80, 256);
	
	mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 320);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 384);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 64, 448);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 0);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 64);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 128);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 192);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 256);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 320);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 384);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 128, 448);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 0);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 64);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 128);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 192);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 256);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 320);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 384);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 192, 448);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 0);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 64);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 128);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 192);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 256);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 320);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 384);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 256, 448);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 0);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 64);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 128);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 192);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 256);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 320);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 384);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 320, 448);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 0);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 64);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 128);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 192);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 256);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 320);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 384);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 384, 448);
	
	mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 0);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 64);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 128);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 192);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 256);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 320);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 384);
	mlx_put_image_to_window(mlx, mlx_win, tiles, 448, 448);
	
	
	mlx_loop(mlx);
	return (0);
}
