#ifndef INIT_H
# define INIT_H

int		init_cam(t_cam *cam, int width, int height);
int		init_mlx(t_mlx *mlx, int width, int height);
int		init_ray(t_ray *ray, t_data *data, double u, double v);
int		init_canvas(t_canvas *canvas, t_mlx *mlx);
int		init(t_data *data, t_mlx *mlx, t_canvas *canvas);
t_vec	init_vec(double x, double y, double z);
int		set_cam_vec(t_cam *cam);
int		set_left_bottom(t_cam *cam);
int		set_intersection(double discrim, double a, double b, t_hit_record *record);
int		set_front_face(t_ray *r, t_hit_record *record);

# endif