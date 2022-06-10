#include "minirt.h"

void	print_a_light(t_data data)
{
	printf("A %f  %f,%f,%f\n", \
		data.a_light.light_ratio, \
		data.a_light.rgb[R], data.a_light.rgb[G], data.a_light.rgb[B]);
}

void	print_light(t_data data)
{
	printf("L %f,%f,%f  %f  %f,%f,%f\n", \
		data.light.coord[X], data.light.coord[Y], data.light.coord[Z], \
		data.light.light_ratio, \
		data.light.rgb[R], data.light.rgb[G], data.light.rgb[B]);
}

void	print_cam(t_data data)
{
	printf("C %f,%f,%f  %f,%f,%f  %f\n", \
		data.cam.coord[X], data.cam.coord[Y], data.cam.coord[Z], \
		data.cam.norm_vec[X], data.cam.norm_vec[Y], data.cam.norm_vec[Z], \
		data.cam.fov);
}

void	print_sph(t_obj *obj)
{
	if 	(obj->id != SP)
		return ;
	printf("sp %f,%f,%f  %f  %f,%f,%f\n", \
		obj->coord[X], obj->coord[Y], obj->coord[Z], \
		obj->diameter, \
		obj->rgb[R], obj->rgb[G], obj->rgb[B]);
}

void	print_pl(t_obj *obj)
{
	if (obj->id != PL)
		return ;
	printf("pl %f,%f,%f  %f,%f,%f  %f,%f,%f\n", \
		obj->coord[X], obj->coord[Y], obj->coord[Z], \
		obj->norm_vec[X], obj->norm_vec[Y], obj->norm_vec[Z], \
		obj->rgb[R], obj->rgb[G], obj->rgb[B]);
}
