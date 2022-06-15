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
		return (print_error("Error\n", 1));
	print_data(data);
	for (int j = data.height - 1; j >= 0; j--)
	{
		for (int i = 0; i < data.width; i++)
		{
			t_ray ray;
			t_color	color;

			double u, v;
			u = (double)i / (data.width - 1);
			v = (double)j / (data.height - 1);
			init_ray(&ray, &data, u, v);
			color = ray_color(&ray, data.objs);
			img_pixel_put(&canvas, i, data.height - 1 - j, &color);
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
