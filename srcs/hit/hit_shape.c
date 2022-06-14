#include "minirt.h"

int	hit_sphere(t_obj *sp, t_ray *r)
{
	t_vec   oc;
	double	a;
	double	b;
	double	c;
	double	discrim;

    oc = vec_minus(r->point, sp->point);
	a = vec_dot(r->vec, r->vec);
	b = vec_dot(oc, r->vec) * 2.;
	c = vec_dot(oc, oc) - pow((sp->diameter / 2), 2.);
	discrim = b * b - 4 * a * c;
	return (discrim > 0); 
}
