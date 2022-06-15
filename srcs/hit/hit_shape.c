#include "minirt.h"

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
	set_front_face(r, record);
	return (1);
}
