#include "minirt.h"

int	hit_sphere(t_obj *sp, t_ray *r)
{
	t_vec   oc;
	double	a;
	double	b;
	double	c;
	double	discrim;

    oc = init_vec(r->vec.x - sp->point.x, r->vec.y - sp->point.y, r->vec.z - sp->point.z);
	a = pow(r->vec.x, 2.) + pow(r->vec.y , 2.) + pow(r->vec.z, 2.);
	b = ((r->vec.x * oc.x) + (r->vec.y * oc.y) + (r->vec.z * oc.z)) * 2.;
	c = (pow(oc.x , 2.) + pow(oc.y, 2.) + pow(oc.z, 2.)) - (pow(sp->diameter / 2., 2.));
	discrim = b * b - 4 * a * c;
	return (discrim > 0); 
}
