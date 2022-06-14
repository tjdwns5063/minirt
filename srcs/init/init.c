#include "minirt.h"

int	init_cam(t_cam *cam)
{
	double	range;
	double	radian;
	double	aspect_ratio;

	radian = degrees_to_radians(cam->fov);
	range = tan(radian / 2);
	aspect_ratio = 16.0 * range / 9.0;
	cam->focal_len = 1.0;
	cam->v_height = 2.0;
	cam->v_width = cam->v_height * aspect_ratio;
	set_cam_vec(cam);
	cam->horizontal = vec_mul_scala(cam->cam_vec.u, cam->v_width);
	cam->vertical = vec_mul_scala(cam->cam_vec.v, cam->v_height);
	cam->left_bottom = vec_minus(cam->point, vec_div_scala(cam->horizontal, 2.));
	cam->left_bottom = vec_minus(cam->left_bottom, vec_div_scala(cam->vertical, 2.));
	cam->left_bottom = vec_minus(cam->left_bottom, cam->cam_vec.w);
	return (1);
}

int	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, 1600, 900, "minirt");
	if (!mlx->win)
		return (0);
	mlx->img = mlx_new_image(mlx->mlx, 1600, 900);
	if (!mlx->img)
		return (0);
	return (1);
}

int	init_canvas(t_canvas *canvas, t_mlx *mlx)
{
	canvas->addr = mlx_get_data_addr(mlx->img, &(canvas->bit_per_pixel), &(canvas->size_line), &(canvas->endian));
	return (1);
}

int	init_ray(t_ray *ray, t_data *data, double u, double v)
{
	ray->point = data->cam.point;
	ray->vec = vec_plus(data->cam.left_bottom, vec_mul_scala(data->cam.horizontal, u));
	ray->vec = vec_plus(ray->vec, vec_mul_scala(data->cam.vertical, v));
	ray->vec = vec_minus(ray->vec, data->cam.point);
	ray->vec = vec_unit(ray->vec);
	return (1);
}