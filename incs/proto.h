#ifndef PROTO_H
# define PROTO_H

typedef struct	s_data		t_data;
typedef struct	s_a_light	t_a_light;
typedef struct	s_light		t_light;
typedef struct	s_cam		t_cam;
typedef struct	s_sphere	t_sphere;
typedef struct	s_plane		t_plane;
typedef struct	s_cylinder	t_cylinder;

struct	s_a_light
{
	double	light_ratio;
	double	rgb[3];
};

struct	s_cam
{
	double	coord[3];
	double	norm_vec[3];
	double	fov;
};

struct	s_light
{
	double	coord[3];
	double	light_ratio;
	double	rgb[3];
};

struct s_sphere
{
	double	coord[3];
	double	diameter;
	double	rgb[3];
};

struct s_plane
{
	double	coord[3];
	double	norm_vec[3];
	double	rgb[3];
};

struct	s_cylinder
{
	double	coord[3];
	double	norm_vec[3];
	double	diameter;
	double	height;
	double	rgb[3];
};

struct	s_data
{
	t_a_light	a_light;
	t_cam		cam;
	t_light		light;
	t_sphere	sph;
	t_plane		pl;
	t_cylinder	cyl;
};

# endif
