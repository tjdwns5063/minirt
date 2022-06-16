#include <minirt.h>

int main(int ac, char **av)
{
	t_data		data;
	t_mlx		mlx;
	t_canvas	canvas;

	if (!check_arg(ac))
		return (print_error("Error\n", 1));
	if (!rt_read(av[1], &data))
		return (print_error("Error\n", 1));
	if (!init(&data, &mlx, &canvas))
	{
		mlx_destroy_image(mlx.mlx, mlx.img);
		mlx_destroy_window(mlx.mlx, mlx.win);
		return (print_error("Error\n", 1));
	}
	print_data(data);
	if (!draw_img(&data, &canvas))
	{
		mlx_destroy_image(mlx.mlx, mlx.img);
		mlx_destroy_window(mlx.mlx, mlx.win);
		return (print_error("Error\n", 1));
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
