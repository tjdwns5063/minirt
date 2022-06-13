#include "minirt.h"

int	parse_a_light(t_data *data, char **tokens)
{
	data->a_light.light_ratio = ft_atof(tokens[1]);
	// data->a_light.rgb[R] = ft_atof(tokens[2]);
	// data->a_light.rgb[G] = ft_atof(tokens[3]);
	// data->a_light.rgb[B] = ft_atof(tokens[4]);
	data->a_light.rgb = init_vec(ft_atof(tokens[2]), ft_atof(tokens[3]), ft_atof(tokens[4]));
	return (1);
}

int	parse_cam(t_data *data, char **tokens)
{
	// data->cam.coord[X] = ft_atof(tokens[1]);
	// data->cam.coord[Y] = ft_atof(tokens[2]);
	// data->cam.coord[Z] = ft_atof(tokens[3]);
	// data->cam.norm_vec[X] = ft_atof(tokens[4]);
	// data->cam.norm_vec[Y] = ft_atof(tokens[5]);
	// data->cam.norm_vec[Z] = ft_atof(tokens[6]);
	data->cam.point = init_vec(ft_atof(tokens[1]), ft_atof(tokens[2]), ft_atof(tokens[3]));
	data->cam.vec = init_vec(ft_atof(tokens[4]), ft_atof(tokens[5]), ft_atof(tokens[6]));
	data->cam.fov = ft_atof(tokens[7]);
	return (1);
}

int	parse_light(t_data *data, char **tokens)
{
	// data->light.coord[X] = ft_atof(tokens[1]);
	// data->light.coord[Y] = ft_atof(tokens[2]);
	// data->light.coord[Z] = ft_atof(tokens[3]);
	data->light.point = init_vec(ft_atof(tokens[1]), ft_atof(tokens[2]), ft_atof(tokens[3]));
	data->light.light_ratio = ft_atof(tokens[4]);
	// data->light.rgb[R] = ft_atof(tokens[5]);
	// data->light.rgb[G] = ft_atof(tokens[6]);
	// data->light.rgb[B] = ft_atof(tokens[7]);
	data->light.rgb = init_vec(ft_atof(tokens[5]), ft_atof(tokens[6]), ft_atof(tokens[7]));
	return (1);
}

int	parse_data(t_data *data, char *line, int id)
{
	char	**tokens;
	int		ret;

	ret = 0;
	convert_line(line);
	tokens = ft_split(line, ' ');
	data->objs = 0;
	if (id == A)
		ret += parse_a_light(data, tokens);
	else if (id == C)
		ret += parse_cam(data, tokens);
	else if (id == L)
		ret += parse_light(data, tokens);
	else if (id == SP)
		ret += parse_sphere(data, tokens, id);
	else if (id == PL)
		ret += parse_plane(data, tokens, id);
	else if (id == CY)
		ret += parse_cylinder(data, tokens, id);
	double_arr_free((void **)tokens);
	return (ret);
}
