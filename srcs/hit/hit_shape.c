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
	if (isnan(record->normal.x) && isnan(record->normal.y) && isnan(record->normal.z))
		return (0);
	record->color = sp->rgb;
	set_front_face(r, record);
	return (1);
}

int	hit_plane(t_obj *pl, t_ray *r, t_hit_record *record)
{
	double	a;
	double	b;
	double	c;
	double	discrim;
	t_vec	vec;

	vec = vec_minus(pl->point, r->point);
	a = 0.;
	b = vec_dot(pl->vec, r->vec);
	c = vec_dot(pl->vec, vec);
	discrim = b * b - a * c;
	if (c != 0)
	{
		record->t = b / c;
	}
	record->normal = vec_unit(vec_minus(ray_at(r, record->t), pl->point));
	if (isnan(record->normal.x) && isnan(record->normal.y) && isnan(record->normal.z))
		return (0);
	record->color = pl->rgb;
	set_front_face(r, record);
	return (1);
}
