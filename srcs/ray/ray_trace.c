#include "minirt.h"

t_color apply_light(t_data *data, t_hit_record *record)
{
    t_color ret;
    t_color ambient;
    t_color diffuse;
    double  angle_of_incidence;
    t_vec   light_to_inter;

    //ambient
    ret = init_vec(0., 0., 0.);
    ambient = vec_mul_scala(vec_div_scala(data->a_light.rgb, 255.), data->a_light.light_ratio);
    ret = vec_plus(ret, ambient);
    //diffuse
    light_to_inter = vec_unit(vec_minus(data->light.point, record->point));
    angle_of_incidence = vec_dot(light_to_inter, record->normal);
    if (angle_of_incidence < 0.0)
        angle_of_incidence = 0.0;
    diffuse = vec_mul_scala(vec_div_scala(record->color, 255.), data->light.light_ratio * angle_of_incidence);
    ret = vec_plus(ret, diffuse);
    return (vec_min(ret, init_vec(1., 1., 1.)));
}

t_color	ray_color(t_data *data, t_ray *r)
{
	double	        t;
	t_color	        ret;
    t_hit_record    record;
    t_obj           *head;

    record.t_min = 0; //t의 최솟값
    record.t_max = INFINITY; // t의 최댓값
    head = data->objs;
	if (hit(head, r, &record))
    {
        ret = apply_light(data, &record);
		return (ret);
    }
	t = 0.5 * (r->vec.y + 1.0);
	ret = vec_plus(
        init_vec(1.0 * (1 - t), 1.0 * (1 - t), (1.0 * 1- t)), 
        init_vec(0.5 * t, 0.7 * t, 1.0 * t));
	return (ret);
}
