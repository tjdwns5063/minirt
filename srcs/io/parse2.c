#include "minirt.h"

int	parse_sphere(t_data *data, char **tokens)
{
	data->sph.coord[X] = ft_atof(tokens[1]);
	data->sph.coord[Y] = ft_atof(tokens[2]);
	data->sph.coord[Z] = ft_atof(tokens[3]);
	data->sph.diameter = ft_atof(tokens[4]);
	data->sph.rgb[R] = ft_atof(tokens[5]);
	data->sph.rgb[G] = ft_atof(tokens[6]);
	data->sph.rgb[B] = ft_atof(tokens[7]);
}

int parse_plane(t_data *data, char **tokens)
{
	data->pl.coord[X] = ft_atof(tokens[1]);
	data->pl.coord[Y] = ft_atof(tokens[2]);
	data->pl.coord[Z] = ft_atof(tokens[3]);
	data->pl.norm_vec[X] = ft_atof(tokens[4]);
	data->pl.norm_vec[Y] = ft_atof(tokens[5]);
	data->pl.norm_vec[Z] = ft_atof(tokens[6]);
	data->pl.rgb[R] = ft_atof(tokens[7]);
	data->pl.rgb[G] = ft_atof(tokens[8]);
	data->pl.rgb[B] = ft_atof(tokens[9]);
}

int parse_cylinder(t_data *data, char **tokens)
{
	data->cyl.coord[X] = ft_atof(tokens[1]);
	data->cyl.coord[Y] = ft_atof(tokens[2]);
	data->cyl.coord[Z] = ft_atof(tokens[3]);
	data->cyl.norm_vec[X] = ft_atof(tokens[4]);
	data->cyl.norm_vec[Y] = ft_atof(tokens[5]);
	data->cyl.norm_vec[Z] = ft_atof(tokens[6]);
	data->cyl.diameter = ft_atof(tokens[7]);
	data->cyl.height = ft_atof(tokens[8]);
	data->cyl.rgb[R] = ft_atof(tokens[9]);
	data->cyl.rgb[G] = ft_atof(tokens[10]);
	data->cyl.rgb[B] = ft_atof(tokens[11]);
}