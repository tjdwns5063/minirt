#include "minirt.h"

int	set_front_face(t_ray *r, t_hit_record *record)
{
	record->front_face = vec_dot(r->vec, record->normal) < 0;
	if (record->front_face == 0)
		record->normal = vec_mul_scala(record->normal, -1.);
	return (1);
}

void	set_vup(t_vec *lookat, t_vec *vup)
{
	if (lookat->x == vup->x && lookat->y == vup->y && lookat->z == vup->z)
	{
		vup->x = 1.;
		vup->y = 0.;
		vup->z = 0.;
	}
}

void	set_lookat(t_vec *lookat, t_vec *lookfrom)
{
	// double	len;

	// len = vec_length(lookfrom);
	// lookat = vec_mul_scala(*lookat, len);
	if (lookfrom->x != 0 || lookfrom->y != 0 || lookfrom->z != 0)
	{
		lookat->x *= rt_abs(lookfrom->x);
		lookat->y *= rt_abs(lookfrom->y);
		lookat->z *= rt_abs(lookfrom->z);
	}
	*lookat = vec_plus(*lookat, *lookfrom);
}



