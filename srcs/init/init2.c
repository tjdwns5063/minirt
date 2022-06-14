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
	vup = init_vec(0, 1, 0);
	cam->cam_vec.w = vec_unit(vec_minus(lookfrom, lookat));
	if (cam->cam_vec.w.x == -3 && cam->cam_vec.w.y == -3 && cam->cam_vec.w.z == -3)
		return (0);
	cam->cam_vec.u = vec_unit(vec_cross(vup, cam->cam_vec.w));
	if (cam->cam_vec.u.x == -3 && cam->cam_vec.u.y == -3 && cam->cam_vec.u.z == -3)
		return (0);
	cam->cam_vec.v = vec_cross(cam->cam_vec.w, cam->cam_vec.u);
	return (1);
}

int	set_left_bottom(t_cam *cam)
{
	t_vec	half_horizontal;
	t_vec	half_vertical;

	half_horizontal = vec_div_scala(cam->horizontal, 2.);
	half_vertical = vec_div_scala(cam->vertical, 2.);
	if ((half_horizontal.x == -3 && half_horizontal.y == -3 && half_horizontal.z == -3) \
	|| (half_vertical.x == -3 && half_vertical.y == -3 && half_vertical.z == -3))
		return (0);
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
