#include <minirt.h>

void	img_pixel_put(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->addr + (y * canvas->size_line) + (x * (canvas->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(int ac, char **av)
{
	t_data	data;
	t_mlx		mlx;
	t_canvas	canvas;

	if (!check_arg(ac))
		return (print_error("Error\n", 1));
	if (!rt_read(av[1], &data))
		return (print_error("Error\n", 1));
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 800, 600, "minirt");
	mlx.img = mlx_new_image(mlx.mlx, 800, 600);


	canvas.addr = mlx_get_data_addr(mlx.img, &(canvas.bit_per_pixel), &(canvas.size_line), &(canvas.endian));
	print_data(data);
	int color = ((int)data.objs->rgb[0] << 16) + ((int)data.objs->rgb[1] << 8) + ((int)data.objs->rgb[2]);
	for (int i = 0; i < 800; i++)
	{
		for (int j = 0; j < 600; j++)
		{
			img_pixel_put(&canvas, i, j, color);
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
