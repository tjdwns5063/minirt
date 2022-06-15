#include "minirt.h"

t_color	ray_color(t_ray *r, t_obj *sp)
{
	double	        t;
	t_color	        ret;
    t_hit_record    record;
    // t_vec   normal;

    record.t_min = 0; //t의 최솟값
    record.t_max = INFINITY; // t의 최댓값
	if (hit_sphere(sp, r, &record))
    {
        ret = vec_mul_scala(init_vec(record.normal.x + 1, record.normal.y + 1, record.normal.z + 1), 0.5);
		return (ret);
    }
	t = 0.5 * (r->vec.y + 1.0);
	ret = vec_plus(
        init_vec(1.0 * (1 - t), 1.0 * (1 - t), (1.0 * 1- t)), 
        init_vec(0.5 * t, 0.7 * t, 1.0 * t));
	return (ret);
}
