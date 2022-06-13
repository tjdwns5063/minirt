#include "minirt.h"

int	init_cam(t_cam *cam)
{
	cam->focal_len = 1.0;
	cam->v_height = 2.0;
	cam->v_width = cam->v_height * (800 / 600);
	// cam->horizontal[X] = cam->v_width;
	// cam->horizontal[Y] = 0;
	// cam->horizontal[Z] = 0;
	cam->horizontal = init_vec(cam->v_width, 0, 0);
	// cam->vertical[X] = 0;
	// cam->vertical[Y] = cam->v_height;
	// cam->vertical[Z] = 0;
	cam->vertical = init_vec(0, cam->v_height, 0);
	// cam->left_bottom[X] = cam->coord[X] - (cam->horizontal[X] / 2.);
	// cam->left_bottom[Y] = cam->coord[Y] - (cam->vertical[Y] / 2.);
	// cam->left_bottom[Z] = cam->coord[Z] - (cam->focal_len);
	cam->left_bottom = init_vec(
						cam->point.x - (cam->horizontal.x / 2.), \
						cam->point.y - (cam->vertical.y / 2.), \
						cam->point.z - cam->focal_len);
	return (1);
}

int	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, 800, 600, "minirt");
	if (!mlx->win)
		return (0);
	mlx->img = mlx_new_image(mlx->mlx, 800, 600);
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
	double	len;

	// if (!ft_memcpy(ray->coord, data->cam.coord, 3))
	// 	return (0);
	ray->point = data->cam.point;
	// ray->vec[X] = data->cam.left_bottom[X] + data->cam.horizontal[X] * u - ray->coord[X];
	// ray->vec[Y] = data->cam.left_bottom[Y] + data->cam.vertical[Y] * v - ray->coord[Y];
	// ray->vec[Z] = data->cam.left_bottom[Z] - ray->coord[Z];
	ray->vec = \
		init_vec(data->cam.left_bottom.x + data->cam.horizontal.x * u - ray->point.x, \
				data->cam.left_bottom.y + data->cam.vertical.y * v - ray->point.y, \
				data->cam.left_bottom.z - ray->point.z);
	len = v_length(&(ray->vec));
	ray->vec.x /= len;
	ray->vec.y /= len;
	ray->vec.z /= len;
	return (1);
}