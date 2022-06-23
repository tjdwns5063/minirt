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
	// printf("sphere_t: %f\n", record->t);
	record->point = ray_at(r, record->t);
	record->normal = vec_unit(vec_minus(record->point, sp->point));
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
	b = vec_dot(r->vec, pl->vec);
	c = vec_dot(pl->vec, vec);
	discrim = b * b - 4 * a * c;
	if (discrim < 0 || c == 0)
	{
		printf("discrim\n");
		return (0);
	}
	// if (!check_root(b / c, record))
	// {
	// 	printf("root\n");
	// 	return (0);
	// }
	record->t = b / c;
	record->point = ray_at(r, record->t);
	vec = vec_unit(vec_minus(record->point, pl->point));
	record->normal = vec_cross(vec, pl->vec);
	record->color = pl->rgb;
	return (1);
}
