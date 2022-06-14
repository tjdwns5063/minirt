#include "minirt.h"

t_vec   vec_mul_scala(t_vec v, double s)
{
    t_vec   ret;

    ret.x = v.x * s;
    ret.y = v.y * s;
    ret.z = v.z * s;
    return (ret);
}

t_vec   vec_div_scala(t_vec v, double s)
{
    t_vec   ret;

    if (s == 0.)
    {
        ret.x = -3;
        ret.y = -3;
        ret.z = -3;
        return (ret);
    }
    ret.x = v.x / s;
    ret.y = v.y / s;
    ret.z = v.z / s;
    return (ret);
}

double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}