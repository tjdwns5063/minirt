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
	return (ret);
}

int	hit_sphere(t_obj *sp, t_ray *r, t_hit_record *record)
{
	t_vec   oc;
	double	a;
	double	b;
	double	c;
	double	discrim;

    oc = vec_minus(r->point, sp->point);
	a = vec_dot(r->vec, r->vec);
	b = vec_dot(oc, r->vec);
	c = vec_dot(oc, oc) - pow((sp->diameter / 2), 2.);
	discrim = b * b - a * c;
	if (!set_intersection(discrim, a, b, record))
		return (0);
	record->normal = vec_unit(vec_minus(ray_at(r, record->t), sp->point));
	record->color = sp->rgb;
	set_front_face(r, record);
	return (1);
}
