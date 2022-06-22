#include "minirt.h"

int	parse_a_light(t_data *data, char **tokens)
{
	data->a_light.light_ratio = ft_atof(tokens[1]);
	data->a_light.rgb = init_vec(ft_atof(tokens[2]) / 255.,\
	 ft_atof(tokens[3]) / 255.,\
	 ft_atof(tokens[4]) / 255.);
	return (1);
}

int	parse_cam(t_data *data, char **tokens)
{
	data->cam.point = init_vec(ft_atof(tokens[1]), ft_atof(tokens[2]), ft_atof(tokens[3]));
	data->cam.vec = init_vec(ft_atof(tokens[4]), ft_atof(tokens[5]), ft_atof(tokens[6]));
	data->cam.fov = ft_atof(tokens[7]);
	return (1);
}

int	parse_light(t_data *data, char **tokens)
{
	data->light.point = init_vec(ft_atof(tokens[1]), ft_atof(tokens[2]), ft_atof(tokens[3]));
	data->light.light_ratio = ft_atof(tokens[4]);
	data->light.rgb = init_vec(ft_atof(tokens[5]) / 255.,\
	 ft_atof(tokens[6]) / 255.,\
	 ft_atof(tokens[7]) / 255.);
	return (1);
}

int	parse_data(t_data *data, char *line, int id)
{
	char	**tokens;
	int		ret;

	ret = 0;
	convert_line(line);
	tokens = ft_split(line, ' ');
	if (id == A)
		ret += parse_a_light(data, tokens);
	if (id == C)
		ret += parse_cam(data, tokens);
	if (id == L)
		ret += parse_light(data, tokens);
	if (id == SP)
		ret += parse_sphere(data, tokens, id);
	if (id == PL)
		ret += parse_plane(data, tokens, id);
	if (id == CY)
		ret += parse_cylinder(data, tokens, id);
	double_arr_free((void **)tokens);
	return (ret);
}
