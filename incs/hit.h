#ifndef HIT_H
# define HIT_H

int	hit(t_obj *objs, t_ray *ray, t_hit_record *record);
int	hit_objs(t_obj *objs, t_ray *ray, t_hit_record *record);
int	hit_sphere(t_obj *sp, t_ray *r, t_hit_record *record);

# endif