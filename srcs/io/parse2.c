#include "minirt.h"

int	parse_sphere(t_data *data, char **tokens, int id)
{
	t_obj	*sph;

	sph = lst_new(id);
	if (!sph)
		return (0);
	// sph->coord[X] = ft_atof(tokens[1]);
	// sph->coord[Y] = ft_atof(tokens[2]);
	// sph->coord[Z] = ft_atof(tokens[3]);
	sph->point = init_vec(ft_atof(tokens[1]), ft_atof(tokens[2]), ft_atof(tokens[3]));
	sph->diameter = ft_atof(tokens[4]);
	// sph->rgb[R] = ft_atof(tokens[5]);
	// sph->rgb[G] = ft_atof(tokens[6]);
	// sph->rgb[B] = ft_atof(tokens[7]);
	sph->rgb = init_vec(ft_atof(tokens[5]), ft_atof(tokens[6]), ft_atof(tokens[7]));
	lst_addback(&(data->objs), sph);
	return (1);
}

int parse_plane(t_data *data, char **tokens, int id)
{
	t_obj	*pl;

	pl = lst_new(id);
	if (!pl)
		return (0);
	// pl->coord[X] = ft_atof(tokens[1]);
	// pl->coord[Y] = ft_atof(tokens[2]);
	// pl->coord[Z] = ft_atof(tokens[3]);
	pl->point = init_vec(ft_atof(tokens[1]), ft_atof(tokens[2]), ft_atof(tokens[3]));
	// pl->norm_vec[X] = ft_atof(tokens[4]);
	// pl->norm_vec[Y] = ft_atof(tokens[5]);
	// pl->norm_vec[Z] = ft_atof(tokens[6]);
	pl->vec = init_vec(ft_atof(tokens[4]), ft_atof(tokens[5]), ft_atof(tokens[6]));
	// pl->rgb[R] = ft_atof(tokens[7]);
	// pl->rgb[G] = ft_atof(tokens[8]);
	// pl->rgb[B] = ft_atof(tokens[9]);
	pl->rgb = init_vec(ft_atof(tokens[7]), ft_atof(tokens[8]), ft_atof(tokens[9]));
	lst_addback(&(data->objs), pl);
	return (1);
}

int parse_cylinder(t_data *data, char **tokens, int id)
{
	t_obj	*cyl;

	cyl = lst_new(id);
	if (!cyl)
		return (0);
	// cyl->coord[X] = ft_atof(tokens[1]);
	// cyl->coord[Y] = ft_atof(tokens[2]);
	// cyl->coord[Z] = ft_atof(tokens[3]);
	cyl->point = init_vec(ft_atof(tokens[1]), ft_atof(tokens[2]), ft_atof(tokens[3]));
	// cyl->norm_vec[X] = ft_atof(tokens[4]);
	// cyl->norm_vec[Y] = ft_atof(tokens[5]);
	// cyl->norm_vec[Z] = ft_atof(tokens[6]);
	cyl->vec = init_vec(ft_atof(tokens[4]), ft_atof(tokens[5]), ft_atof(tokens[6]));
	cyl->diameter = ft_atof(tokens[7]);
	cyl->height = ft_atof(tokens[8]);
	// cyl->rgb[R] = ft_atof(tokens[9]);
	// cyl->rgb[G] = ft_atof(tokens[10]);
	// cyl->rgb[B] = ft_atof(tokens[11]);
	cyl->rgb = init_vec(ft_atof(tokens[9]), ft_atof(tokens[10]), ft_atof(tokens[11]));
	lst_addback(&(data->objs), cyl);
	return (1);
}