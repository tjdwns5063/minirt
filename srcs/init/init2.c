#include "minirt.h"

t_vec	init_vec(double x, double y, double z)
{
	t_vec	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

int	set_cam_vec(t_cam *cam)
{
	t_vec	lookfrom;
	t_vec	lookat;
	t_vec	vup;

	lookfrom = cam->point;
	lookat = cam->vec;
	vup = init_vec(0., 1., 0.);
	set_vup(&lookat, &vup);
	set_lookat(&lookat, &lookfrom);
	// print_vec(&lookat);
	// print_vec(&vup);
	cam->cam_vec.w = vec_unit(vec_minus(lookfrom, lookat));
	cam->cam_vec.u = vec_unit(vec_cross(vup, cam->cam_vec.w));
	cam->cam_vec.v = vec_cross(cam->cam_vec.w, cam->cam_vec.u);
	printf("w.x: %f w.y: %f w.z: %f\n", cam->cam_vec.w.x, cam->cam_vec.w.y, cam->cam_vec.w.z);
	printf("u.x: %f u.y: %f u.z: %f\n", cam->cam_vec.u.x, cam->cam_vec.u.y, cam->cam_vec.u.z);
	printf("v.x: %f v.y: %f v.z: %f\n", cam->cam_vec.v.x, cam->cam_vec.v.y, cam->cam_vec.v.z);
	return (1);
}

int	set_left_bottom(t_cam *cam)
{
	t_vec	half_horizontal;
	t_vec	half_vertical;

	half_horizontal = vec_div_scala(cam->horizontal, 2.);
	half_vertical = vec_div_scala(cam->vertical, 2.);
	cam->left_bottom = vec_minus(cam->point, half_horizontal);
	cam->left_bottom = vec_minus(cam->left_bottom, half_vertical);
	cam->left_bottom = vec_minus(cam->left_bottom, cam->cam_vec.w);
	return (1);
}

int	init(t_data *data, t_mlx *mlx, t_canvas *canvas)
{
	data->width = 800;
	data->height = 450;
	if (!init_cam(&(data->cam), data->width, data->height))
		return (0);
	if (!init_mlx(mlx, data->width, data->height))
		return (0);
	init_canvas(canvas, mlx);
	return (1);
}

int	set_intersection(double discrim, double a, double b, t_hit_record *record)
{
	int	condition;

	condition = check_discrim(discrim, a, b, record);
	if (!condition)
		return (0);
	else if (condition < 0)
		record->t = -b - sqrt(discrim) / (2 * a);
	record->t = -b + sqrt(discrim) / (2 * a);
	// printf("%f\n", record->t);
	return (1);
}
