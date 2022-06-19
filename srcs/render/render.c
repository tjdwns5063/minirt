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

int	draw_img(t_data *data, t_canvas *canvas)
{
	t_ray	ray;
	t_color	color;
	int	i;
	int	j;

	j = data->height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < data->width)
		{
			if (!init_ray(&ray, data, i, j))
				return (0);
			color = ray_color(data, &ray);
			img_pixel_put(canvas, i, data->height - 1 - j, &color);
		}
	}
	return (1);
}
