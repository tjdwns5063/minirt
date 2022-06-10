#include "minirt.h"

void	print_cyl(t_obj *obj)
{
	if (obj->id != CY)
		return ;
	printf("cy %f,%f,%f  %f,%f,%f  %f  %f  %f,%f,%f\n", \
		obj->coord[X], obj->coord[Y], obj->coord[Z], \
		obj->norm_vec[X], obj->norm_vec[Y], obj->norm_vec[Z], \
		obj->diameter, obj->height, \
		obj->rgb[R], obj->rgb[G], obj->rgb[B]);
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
