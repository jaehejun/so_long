/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:18:08 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/10 22:13:28 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 448, 448, "so_long");
	img = mlx_xpm_file_to_image(mlx, "./desert.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img, 0, 64);
	mlx_put_image_to_window(mlx, win, img, 0, 128);
	mlx_put_image_to_window(mlx, win, img, 0, 192);
	mlx_put_image_to_window(mlx, win, img, 0, 256);
	mlx_put_image_to_window(mlx, win, img, 0, 320);
	mlx_put_image_to_window(mlx, win, img, 0, 384);
	mlx_put_image_to_window(mlx, win, img, 0, 448);
	mlx_put_image_to_window(mlx, win, img, 64, 0);
	mlx_put_image_to_window(mlx, win, img, 64, 64);
	mlx_put_image_to_window(mlx, win, img, 64, 128);
	mlx_put_image_to_window(mlx, win, img, 64, 192);
	mlx_put_image_to_window(mlx, win, img, 64, 256);
	mlx_put_image_to_window(mlx, win, img, 64, 320);
	mlx_put_image_to_window(mlx, win, img, 64, 384);
	mlx_put_image_to_window(mlx, win, img, 64, 448);
	mlx_put_image_to_window(mlx, win, img, 128, 0);
	mlx_put_image_to_window(mlx, win, img, 128, 64);
	mlx_put_image_to_window(mlx, win, img, 128, 128);
	mlx_put_image_to_window(mlx, win, img, 128, 192);
	mlx_put_image_to_window(mlx, win, img, 128, 256);
	mlx_put_image_to_window(mlx, win, img, 128, 320);
	mlx_put_image_to_window(mlx, win, img, 128, 384);
	mlx_put_image_to_window(mlx, win, img, 128, 448);
	mlx_put_image_to_window(mlx, win, img, 192, 0);
	mlx_put_image_to_window(mlx, win, img, 192, 64);
	mlx_put_image_to_window(mlx, win, img, 192, 128);
	mlx_put_image_to_window(mlx, win, img, 192, 192);
	mlx_put_image_to_window(mlx, win, img, 192, 256);
	mlx_put_image_to_window(mlx, win, img, 192, 320);
	mlx_put_image_to_window(mlx, win, img, 192, 384);
	mlx_put_image_to_window(mlx, win, img, 192, 448);
	mlx_put_image_to_window(mlx, win, img, 256, 0);
	mlx_put_image_to_window(mlx, win, img, 256, 64);
	mlx_put_image_to_window(mlx, win, img, 256, 128);
	mlx_put_image_to_window(mlx, win, img, 256, 192);
	mlx_put_image_to_window(mlx, win, img, 256, 256);
	mlx_put_image_to_window(mlx, win, img, 256, 320);
	mlx_put_image_to_window(mlx, win, img, 256, 384);
	mlx_put_image_to_window(mlx, win, img, 256, 448);
	mlx_put_image_to_window(mlx, win, img, 320, 0);
	mlx_put_image_to_window(mlx, win, img, 320, 64);
	mlx_put_image_to_window(mlx, win, img, 320, 128);
	mlx_put_image_to_window(mlx, win, img, 320, 192);
	mlx_put_image_to_window(mlx, win, img, 320, 256);
	mlx_put_image_to_window(mlx, win, img, 320, 320);
	mlx_put_image_to_window(mlx, win, img, 320, 384);
	mlx_put_image_to_window(mlx, win, img, 320, 448);
	mlx_put_image_to_window(mlx, win, img, 384, 0);
	mlx_put_image_to_window(mlx, win, img, 384, 64);
	mlx_put_image_to_window(mlx, win, img, 384, 128);
	mlx_put_image_to_window(mlx, win, img, 384, 192);
	mlx_put_image_to_window(mlx, win, img, 384, 256);
	mlx_put_image_to_window(mlx, win, img, 384, 320);
	mlx_put_image_to_window(mlx, win, img, 384, 384);
	mlx_put_image_to_window(mlx, win, img, 384, 448);
	
	mlx_put_image_to_window(mlx, win, img, 448, 0);
	mlx_put_image_to_window(mlx, win, img, 448, 64);
	mlx_put_image_to_window(mlx, win, img, 448, 128);
	mlx_put_image_to_window(mlx, win, img, 448, 192);
	mlx_put_image_to_window(mlx, win, img, 448, 256);
	mlx_put_image_to_window(mlx, win, img, 448, 320);
	mlx_put_image_to_window(mlx, win, img, 448, 384);
	mlx_put_image_to_window(mlx, win, img, 448, 448);
	
	
	mlx_loop(mlx);
	return (0);
}
