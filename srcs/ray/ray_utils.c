#include "minirt.h"

t_point ray_at(t_ray *r, double t)
{
    t_point ret;

    ret = vec_plus(r->point, vec_mul_scala(r->vec, t));
    return (ret);
}
