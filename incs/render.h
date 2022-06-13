#ifndef RENDER_H
# define RENDER_H

void	img_pixel_put(t_canvas *canvas, int x, int y, t_color *color);
t_color	get_color(t_ray *r, t_obj *sp);
int     get_rgb_value(t_color *color);

# endif