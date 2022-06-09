#include "minirt.h"

int	parse_a_light(t_data *data, char **tokens)
{
	data->a_light.light_ratio = ft_atof(tokens[1]);
	data->a_light.rgb[R] = ft_atof(tokens[2]);
	data->a_light.rgb[G] = ft_atof(tokens[3]);
	data->a_light.rgb[B] = ft_atof(tokens[4]);
}

int	parse_cam(t_data *data, char **tokens)
{
	data->cam.coord[X] = ft_atof(tokens[1]);
	data->cam.coord[Y] = ft_atof(tokens[2]);
	data->cam.coord[Z] = ft_atof(tokens[3]);
	data->cam.norm_vec[X] = ft_atof(tokens[4]);
	data->cam.norm_vec[Y] = ft_atof(tokens[5]);
	data->cam.norm_vec[Z] = ft_atof(tokens[6]);
	data->cam.fov = ft_atof(tokens[7]);
}

int	parse_light(t_data *data, char **tokens)
{
	data->light.coord[X] = ft_atof(tokens[1]);
	data->light.coord[Y] = ft_atof(tokens[2]);
	data->light.coord[Z] = ft_atof(tokens[3]);
	data->light.light_ratio = ft_atof(tokens[4]);
	data->light.rgb[R] = ft_atof(tokens[5]);
	data->light.rgb[G] = ft_atof(tokens[6]);
	data->light.rgb[B] = ft_atof(tokens[7]);
}

int	parse_data(t_data *data, char *line, int id)
{
	char	**tokens;

	convert_line(line);
	tokens = ft_split(line, ' ');
	if (id == A)
		parse_a_light(data, tokens);
	else if (id == C)
		parse_cam(data, tokens);
	else if (id == L)
		parse_light(data, tokens);
	else if (id == SP)
		parse_sphere(data, tokens);
	else if (id == PL)
		parse_plane(data, tokens);
	else if (id == CY)
		parse_cylinder(data, tokens);
	double_arr_free((void **)tokens);
	return (0);
}

int	parse(int fd, t_data *data)
{
	char	*line;
	int		id;

	while (get_next_line(fd, &line))
	{
		if (check_empty_line(line))
		{
			free(line);
			continue ;
		}
		id = check_format(line);
		if (!id)
		{
			free(line);
			return (0);
		}
		parse_data(data, line, id);
		free(line);
	}
	free(line);
	return (1);
}