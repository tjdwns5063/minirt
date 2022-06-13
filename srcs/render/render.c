#include "minirt.h"

void	img_pixel_put(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->addr + (y * canvas->size_line) + (x * (canvas->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_ray *r, t_obj *sp)
{
	double	t;
	double	c1[3];
	double	c2[3];
	int		ret;

	// if (hit_sphere(sp, r))
	// 	return (255 << 16);
	t = 0.5 * (r->vec[Y] + 1.0);
	c1[R] = 255 * t;
	c1[G] = 255 * t;
	c1[B] = 255 * t;
	c2[R] = (255 * 0.5) * (1 - t);
	c2[G] = (255 * 0.7) * (1 - t);
	c2[B] = 255 * (1 - t);
	ret = (((int)(c1[R] + c2[R])) << 16) + (((int)(c1[G] + c2[G])) << 8) + ((int)(c1[B] + c2[B]));
	return (ret);
}

