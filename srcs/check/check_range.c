#include "minirt.h"

int	check_rgb_range(t_data *data)
{
	t_obj	*head;

	head = data->objs;
	while (head)
	{
		if (head->rgb[R] < 0 || head->rgb[G] < 0 || head->rgb[B] < 0 || \
			head->rgb[R] > 255 || head->rgb[G] > 255 || head->rgb[B] > 255)
				return (0);
		head = head->next;
	}
	return (0 <= data->a_light.rgb[R] && data->a_light.rgb[R] <= 255 && \
		0 <= data->a_light.rgb[G] && data->a_light.rgb[G] <= 255 && \
		0 <= data->a_light.rgb[B] && data->a_light.rgb[B] <= 255 && \
		0 <= data->light.rgb[R] && data->light.rgb[R] <= 255 && \
		0 <= data->light.rgb[G] && data->light.rgb[G] <= 255 && \
		0 <= data->light.rgb[B] && data->light.rgb[B] <= 255);
}

int	check_vec_range(t_data *data)
{
	t_obj	*head;

	head = data->objs;
	while (head)
	{
		if ((head->id == PL || head->id == CY) && \
			(head->norm_vec[X] < -1 || head->norm_vec[Y] < -1 || head->norm_vec[Z] < -1 \
			|| head->norm_vec[X] > 1 || head->norm_vec[Y] > 1 || head->norm_vec[Z] > 1))
				return (0);
		head = head->next;
	}
	return (-1 <= data->cam.norm_vec[X] && data->cam.norm_vec[X] <= 1 && \
		-1 <= data->cam.norm_vec[Y] && data->cam.norm_vec[Y] <= 1 && \
		-1 <= data->cam.norm_vec[Z] && data->cam.norm_vec[Z] <= 1);
}

int	check_light_ratio_range(t_data *data)
{
	return (0.0 <= data->a_light.light_ratio && data->a_light.light_ratio <= 1.0 && \
		0.0 <= data->light.light_ratio && data->light.light_ratio <= 1.0);
}

int	check_degree_range(t_data *data)
{
	return (0 <= data->cam.fov && data->cam.fov <= 180);
}

int	check_data(t_data *data)
{
	return (check_rgb_range(data) && check_vec_range(data) && \
		check_light_ratio_range(data) && check_degree_range(data));
}
