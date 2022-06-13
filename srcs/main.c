#include <minirt.h>

// int	hit_sphere(t_obj *sp, t_ray *r)
// {
// 	double	oc[3];
// 	double	a;
// 	double	b;
// 	double	c;
// 	double	discrim;

// 	oc[X] = r->vec[X] - sp->coord[X];
// 	oc[Y] = r->vec[Y] - sp->coord[Y];
// 	oc[Z] = r->vec[Z] - sp->coord[Z];
// 	a = pow(r->vec[X], 2.) + pow(r->vec[Y] , 2.) + pow(r->vec[Z], 2.);
// 	b = ((r->vec[X] * oc[X]) + (r->vec[Y] * oc[Y]) + (r->vec[Z] * oc[Z])) * 2.;
// 	c = (pow(oc[X] , 2.) + pow(oc[Y], 2.) + pow(oc[Z], 2.)) - (pow(sp->diameter / 2., 2.));
// 	discrim = b * b - 4 * a * c;
// 	return (discrim > 0); 
// }

int main(int ac, char **av)
{
	t_data	data;
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
