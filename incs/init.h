#ifndef INIT_H
# define INIT_H

int	init_cam(t_cam *cam);
int init_mlx(t_mlx *mlx);
int	init_ray(t_ray *ray, t_data *data, double u, double v);
int	init_canvas(t_canvas *canvas, t_mlx *mlx);


# endif