#include "minirt.h"

int	get_rgb_value(t_color *color)
{
	int	r;
	int	g;
	int	b;

	r = ((int)(color->x * 255.)) << 16;
	g = ((int)(color->y * 255.)) << 8;
	b = (int)(color->z * 255.);
	// printf("rgb: %d\n", r+g+b);
	return (r + g + b);
}

void	img_pixel_put(t_canvas *canvas, int x, int y, t_color *color)
{
	char	*dst;

	dst = canvas->addr + (y * canvas->size_line) + (x * (canvas->bit_per_pixel / 8));
	*(unsigned int *)dst = get_rgb_value(color);
}

t_color	get_color(t_ray *r, t_obj *sp)
{
	double	t;
	t_color	c1;
	t_color	c2;
	t_color	ret;

	// if (hit_sphere(sp, r))
	// 	return (255 << 16);
	t = 0.5 * (r->vec.y + 1.0);
	c1 = init_vec(1.0 * t, 1.0 * t, 1.0 * t);
	c2 = init_vec(0.5 * (1 - t), 0.7 * (1 - t), 1.0 * (1 - t));
	ret = vec_plus(c1, c2);
	return (ret);
}

