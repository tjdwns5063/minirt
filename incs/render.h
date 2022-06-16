#ifndef RENDER_H
# define RENDER_H

void	img_pixel_put(t_canvas *canvas, int x, int y, t_color *color);
int     get_rgb_value(t_color *color);
int		draw_img(t_data *data, t_canvas *canvas);

# endif