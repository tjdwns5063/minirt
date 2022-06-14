#include "minirt.h"

t_vec	init_vec(double x, double y, double z)
{
	t_vec	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

void	set_cam_vec(t_cam *cam)
{
	t_vec	lookfrom;
	t_vec	lookat;
	t_vec	vup;

	lookfrom = cam->point;
	lookat = cam->vec;
	vup = init_vec(0, 1, 0);
	cam->cam_vec.w = vec_unit(vec_minus(lookfrom, lookat));
	cam->cam_vec.u = vec_unit(vec_cross(vup, cam->cam_vec.w));
	cam->cam_vec.v = vec_cross(cam->cam_vec.w, cam->cam_vec.u);
}