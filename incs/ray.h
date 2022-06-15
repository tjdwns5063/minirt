#ifndef RAY_H
# define RAY_H

t_color	ray_color(t_data *data, t_ray *r);
t_point ray_at(t_ray *r, double t);
t_color apply_light(t_data *data, t_hit_record *record);

# endif
