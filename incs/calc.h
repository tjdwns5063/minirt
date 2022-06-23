#ifndef CALC_H
# define CALC_H

double	vec_length(t_vec *vec);
t_vec	vec_plus(t_vec v1, t_vec v2);
t_vec	vec_minus(t_vec v1, t_vec v2);
double  degrees_to_radians(double degree);
t_vec	vec_cross(t_vec v1, t_vec v2);
double	vec_dot(t_vec v1, t_vec v2);
t_vec	vec_unit(t_vec v);
t_vec   vec_min(t_vec v1, t_vec v2);
t_vec   vec_mul_scala(t_vec v, double s);
t_vec   vec_div_scala(t_vec v, double s);
double  rt_abs(double d);

# endif