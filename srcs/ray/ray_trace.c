#include "minirt.h"

t_color	ray_color(t_ray *r, t_obj *sp)
{
	double	t;
	t_color	ret;
    t_vec   normal;

    t = hit_sphere(sp, r);
	if (t > 0.0)
    {
        normal = vec_unit(vec_minus(ray_at(r, t), sp->point));
        ret = vec_mul_scala(init_vec(normal.x + 1, normal.y + 1, normal.z + 1), 0.5);
		return (ret);
    }
	t = 0.5 * (r->vec.y + 1.0);
	ret = vec_plus(
        init_vec(1.0 * (1 - t), 1.0 * (1 - t), (1.0 * 1- t)), 
        init_vec(0.5 * t, 0.7 * t, 1.0 * t));
	return (ret);
}
