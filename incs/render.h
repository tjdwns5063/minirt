#ifndef RENDER_H
# define RENDER_H

void	img_pixel_put(t_canvas *canvas, int x, int y, int color);
int		get_color(t_ray *r, t_obj *sp);

# endif