#include "minirt.h"

int	init_cam(t_cam *cam, int width, int height)
{
	double	range;
	double	radian;
	double	aspect_ratio;

	radian = degrees_to_radians(cam->fov);
	range = tan(radian / 2);
	aspect_ratio = 16 / 9;
	cam->focal_len = 1.0;
	cam->v_width = 2.0 * range;
	cam->v_height = cam->v_width * pow(aspect_ratio, -1.);
	set_cam_vec(cam);
	cam->horizontal = vec_mul_scala(cam->cam_vec.u, cam->v_width);
	cam->vertical = vec_mul_scala(cam->cam_vec.v, cam->v_height);
	set_left_bottom(cam);
	return (1);
}

int	init_mlx(t_mlx *mlx, int width, int height)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, width, height, "minirt");
	if (!mlx->win)
		return (0);
	mlx->img = mlx_new_image(mlx->mlx, width, height);
	if (!mlx->img)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		return (0);
	}
	return (1);
}

int	init_canvas(t_canvas *canvas, t_mlx *mlx)
{
	canvas->addr = mlx_get_data_addr(mlx->img, &(canvas->bit_per_pixel), &(canvas->size_line), &(canvas->endian));
	return (1);
}

int	init_ray(t_ray *ray, t_data *data, int i, int j)
{
	double	u;
	double	v;

	u = (double)i / (data->width - 1);
	v = (double)j / (data->height - 1);
	ray->point = data->cam.point;
	ray->vec = vec_plus(data->cam.left_bottom, vec_mul_scala(data->cam.horizontal, u));
	ray->vec = vec_plus(ray->vec, vec_mul_scala(data->cam.vertical, v));
	ray->vec = vec_minus(ray->vec, data->cam.point);
	ray->vec = vec_unit(ray->vec);
	return (1);
}