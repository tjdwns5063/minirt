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
	init_cam(&(data.cam));
	init_mlx(&(mlx));
	init_canvas(&canvas, &mlx);
	print_data(data);
	for (int i = 0; i < 800; i++)
	{
		for (int j = 0; j < 600; j++)
		{
			t_ray ray;
			t_color	color;

			double u, v;
			u = (double)i / 799;
			v = (double)j / 599;
			init_ray(&ray, &data, u, v);
			color = get_color(&ray, data.objs);
			img_pixel_put(&canvas, i, j, &color);
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
