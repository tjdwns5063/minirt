#include "minirt.h"

int	set_front_face(t_ray *r, t_hit_record *record)
{
	record->front_face = vec_dot(r->vec, record->normal) < 0;
	if (record->front_face == 0)
		record->normal = vec_mul_scala(record->normal, -1.);
	return (1);
}