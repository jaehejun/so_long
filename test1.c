#include "./mlx/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();

	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test window");
	// 생성할 윈도우를 가리키는 포인터 (mlx_init이 반환한 연결 식별자, 창의 가로사이즈, 창의 세로사이즈, 타이틀 바에 표시될 문자열)
	// 초기화하지 않은 mlx_ptr이 mlx_new_window에 전달되면 segfault가 발생한다.
	// 창을 생성하는 것 까지만 작동하고 실제로 모니터상에 창을 띄우지는 않는다.

	mlx_loop(mlx_ptr);
	// 이벤트를 받는 함수 (디스플레이에 연결되어 있는 mlx_ptr)
	// loop를 돌면서 event를 기다리고, 생성한 윈도우를 Rendering한다.
	return (0);
}
