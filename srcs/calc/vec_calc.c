#include "minirt.h"

double	vec_length(t_vec *vec)
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

t_vec	vec_minus(t_vec v1, t_vec v2)
{
	t_vec	ret;
	
	ret = init_vec(v1.x - v2.x, v1.y - v2.y, v1.z - v2. z);
	return (ret);
}

t_vec	vec_cross(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.x = v1.y * v2.z - v1.z * v2.y;
	ret.y = v1.z * v2.x - v1.x * v2.z;
	ret.z = v1.x * v2.y - v1.y * v2.x;
	return (ret);
}

t_vec	vec_unit(t_vec v)
{
	double	len;
	t_vec	ret;

	len = vec_length(&v);
	if (len == 0.)
	{
		ret.x = nan(0);
		ret.y = nan(0);
		ret.z = nan(0);
		return (ret);
	}
	ret.x = v.x / len;
	ret.y = v.y / len;
	ret.z = v.z / len;
	return (ret);
}
