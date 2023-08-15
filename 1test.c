#include "./mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>


#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_RELEASE		3

#define KEY_ESC			53
#define KEY_W			13
#define KEY_A			0
#define KEY_S			1
#define KEY_D			2

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 2560, 1344, "mlx_project");
	mlx_pixel_put(mlx, win, 250, 250, 0x00FFFFFF);
	mlx_loop(mlx);

	return (0);
}