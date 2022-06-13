#ifndef PROTO_H
# define PROTO_H

typedef struct	s_data		t_data;
typedef struct	s_a_light	t_a_light;
typedef struct	s_light		t_light;
typedef struct	s_cam		t_cam;
typedef struct	s_obj		t_obj;
typedef struct	s_canvas	t_canvas;
typedef struct	s_mlx		t_mlx;

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

struct s_obj
{
	int				id;
	double			coord[3];
	double			norm_vec[3];
	double			diameter;
	double			height;
	double			rgb[3];
	struct s_obj	*next;
};

struct	s_data
{
	t_a_light	a_light;
	t_cam		cam;
	t_light		light;
	t_obj		*objs;
};

struct s_canvas
{
	char	*addr;
	int 	bit_per_pixel;
	int		size_line;
	int		endian;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
};

# endif
