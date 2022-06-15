#include "minirt.h"

int	get_rgb_value(t_color *color)
{
	int	r;
	int	g;
	int	b;

	r = ((int)(color->x * 255.)) << 16;
	g = ((int)(color->y * 255.)) << 8;
	b = (int)(color->z * 255.);
	return (r + g + b);
}

void	img_pixel_put(t_canvas *canvas, int x, int y, t_color *color)
{
	char	*dst;

	dst = canvas->addr + (y * canvas->size_line + x * (canvas->bit_per_pixel / 8));
	*(unsigned int *)dst = get_rgb_value(color);
}
