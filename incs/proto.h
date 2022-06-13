#ifndef PROTO_H
# define PROTO_H

typedef struct	s_vec		t_vec;
typedef struct	s_vec		t_point;
typedef	struct	s_vec		t_color;
typedef struct	s_data		t_data;
typedef struct	s_a_light	t_a_light;
typedef struct	s_light		t_light;
typedef struct	s_cam		t_cam;
typedef struct	s_ray		t_ray;
typedef struct	s_obj		t_obj;
typedef struct	s_canvas	t_canvas;
typedef struct	s_mlx		t_mlx;

struct s_vec
{
	double	x;
	double	y;
	double	z;
};


struct	s_a_light
{
	double	light_ratio;
	t_color	rgb;
};

struct	s_cam
{
	// double	coord[3];
	t_point	point;
	// double	norm_vec[3];
	t_vec	vec;
	double	fov;
	double	focal_len;
	double	v_height;
	double	v_width;
	// double	horizontal[3];
	t_vec	horizontal;
	// double	vertical[3];
	t_vec	vertical;
	// double	left_bottom[3];
	t_vec	left_bottom;
};

struct	s_light
{
	t_point		point;
	// double	coord[3];
	double		light_ratio;
	// double	rgb[3];
	t_color		rgb;
};

struct s_obj
{
	int				id;
	// double			coord[3];
	t_point			point;
	// double			norm_vec[3];
	t_vec			vec;
	double			diameter;
	double			height;
	// double			rgb[3];
	t_color			rgb;
	struct s_obj	*next;
};

typedef struct s_ray
{
	// double	coord[3];
	t_point		point;
	// double	vec[3];
	t_vec		vec;
}	t_ray;

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
