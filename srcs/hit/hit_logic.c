#include "minirt.h"

int	hit(t_obj *objs, t_ray *ray, t_hit_record *record)
{
	t_obj	*temp;
	int		ret;

	temp = objs;
	ret = 0;
	while (temp)
	{
		if (hit_objs(temp, ray, record))
		{
			ret = 1;
			record->t_max = record->t;
		}
		temp = temp->next;
	}
	return (ret);
}

int	hit_objs(t_obj *objs, t_ray *ray, t_hit_record *record)
{
	int	ret;

	ret = 0;
	if (objs->id == SP)
		ret = hit_sphere(objs, ray, record);
	else if (objs->id == PL)
		ret = hit_plane(objs, ray, record);
	return (ret);
}
