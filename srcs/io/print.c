#include "minirt.h"

void	print_a_light(t_data data)
{
	printf("A %f  %f,%f,%f\n", \
		data.a_light.light_ratio, \
		data.a_light.rgb.x, data.a_light.rgb.y, data.a_light.rgb.z);
}

void	print_light(t_data data)
{
	printf("L %f,%f,%f  %f  %f,%f,%f\n", \
		data.light.point.x, data.light.point.y, data.light.point.z, \
		data.light.light_ratio, \
		data.light.rgb.x, data.light.rgb.y, data.light.rgb.z);
}

void	print_cam(t_data data)
{
	printf("C %f,%f,%f  %f,%f,%f  %f\n", \
		data.cam.point.x, data.cam.point.y, data.cam.point.z, \
		data.cam.vec.x, data.cam.vec.y, data.cam.vec.z, \
		data.cam.fov);
}

void	print_sph(t_obj *obj)
{
	if 	(obj->id != SP)
		return ;
	printf("sp %f,%f,%f  %f  %f,%f,%f\n", \
		obj->point.x, obj->point.y, obj->point.z, \
		obj->diameter, \
		obj->rgb.x, obj->rgb.y, obj->rgb.z);
}

void	print_pl(t_obj *obj)
{
	if (obj->id != PL)
		return ;
	printf("pl %f,%f,%f  %f,%f,%f  %f,%f,%f\n", \
		obj->point.x, obj->point.y, obj->point.z, \
		obj->vec.x, obj->vec.y, obj->vec.z, \
		obj->rgb.x, obj->rgb.y, obj->rgb.z);
}
