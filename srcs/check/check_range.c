#include "minirt.h"

int	check_rgb_range(t_data *data)
{
	t_obj	*head;

	head = data->objs;
	while (head)
	{
		if (head->rgb.x < 0 || head->rgb.y < 0 || head->rgb.z < 0 || \
			head->rgb.x > 255 || head->rgb.y > 255 || head->rgb.z > 255)
				return (0);
		head = head->next;
	}
	return (0 <= data->a_light.rgb.x && data->a_light.rgb.x <= 255 && \
		0 <= data->a_light.rgb.y && data->a_light.rgb.y <= 255 && \
		0 <= data->a_light.rgb.z && data->a_light.rgb.z <= 255 && \
		0 <= data->light.rgb.x && data->light.rgb.x <= 255 && \
		0 <= data->light.rgb.y && data->light.rgb.y <= 255 && \
		0 <= data->light.rgb.z && data->light.rgb.z <= 255);
}

int	check_vec_range(t_data *data)
{
	t_obj	*head;

	head = data->objs;
	while (head)
	{
		if ((head->id == PL || head->id == CY) && \
			(head->vec.x < -1 || head->vec.y < -1 || head->vec.z < -1 \
			|| head->vec.x > 1 || head->vec.y > 1 || head->vec.z > 1))
				return (0);
		head = head->next;
	}
	return (-1 <= data->cam.vec.x && data->cam.vec.x <= 1 && \
		-1 <= data->cam.vec.y && data->cam.vec.y <= 1 && \
		-1 <= data->cam.vec.z && data->cam.vec.z <= 1);
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
