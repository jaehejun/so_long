#include <unistd.h>
#include "./mlx/mlx.h"

//이미지의 정보를 나타내는 변수를 저장한 구조체
typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Test Window");
	image.img = mlx_new_image(mlx_ptr, 500, 500); // 이미지 객체 생성 : 메모리에 새 이미지를 만든다.(지정한 크기만큼의 그림을 보이지 않는 공간에 미리 그려두고 이후 이 이미지를 mlx_put_image_to_window 함수를 통해 윈도우에 그림을 그린다.)
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	// 생성된 이미지에 대한 정보를 리턴한다. (사용할 이미지 지정, 픽셀 색상을 나타내는 데 필요한 비트 수, 이미지 한 줄을 메모리에 저장하는데 사용되는 바이트 수. 이 정보는 이미지의 한 줄에서 다른 줄로 이동하는 데 필요하다, 이미지의 픽셀 색상 저장 방식(little endian = 0, big endian = -1))
	for (int i = 0 ; i < 500 ; i++)
	{
		for (int j = 0 ; j < 500 ; j++)
		{
			mlx_pixel_put (mlx_ptr, win_ptr, i, j, 0x00FFFFFF);
			my_mlx_pixel_put(&image, i, j, 0x00FFFFFF);
		}	
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);
	// 생성한 이미지를 원하는 윈도우에 올려주는 함수 (디스플레이에 연결되어 있는 mlx_ptr, 사용할 윈도우, 사용할 이미지, 이미지를 윈도우에 올릴 x좌표, 이미지를 윈도우에 올릴 y좌표)
	mlx_loop(mlx_ptr);
	return (0);
}