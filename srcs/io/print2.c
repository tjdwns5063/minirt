#include "minirt.h"

void	print_vec(t_vec *vec)
{
	printf("%f, %f, %f", vec->x, vec->y, vec->z);
}

void	print_cyl(t_obj *obj)
{
	if (obj->id != CY)
		return ;
	printf("cy %f,%f,%f  %f,%f,%f  %f  %f  %f,%f,%f\n", \
		obj->point.x, obj->point.y, obj->point.z, \
		obj->vec.x, obj->vec.y, obj->vec.z, \
		obj->diameter, obj->height, \
		obj->rgb.x, obj->rgb.y, obj->rgb.z);
}

void	print_obj(t_obj *obj)
{
	t_obj	*head;

	head = obj;
	while (head)
	{
		print_sph(head);
		print_pl(head);
		print_cyl(head);
		head = head->next;
	}
}

void	print_data(t_data data)
{
	print_a_light(data);
	print_cam(data);
	print_light(data);
	print_obj(data.objs);
}
