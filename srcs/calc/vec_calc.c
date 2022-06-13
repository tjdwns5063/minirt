#include "minirt.h"

double	v_length(t_vec *vec)
{
	double	len;

	len = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (len);
}

t_vec	vec_plus(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret = init_vec(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	return (ret);
}
