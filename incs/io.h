#ifndef IO_H
# define IO_H

int		rt_read(char *filename, t_data *data);
int		double_arr_free(void **content);
int		parse(int fd, t_data *data);
int		get_token_len(char **tokens);
int		print_error(char *err_str, int err_num);
void	convert_line(char *line);
int		parse_data(t_data *data, char *line, int id);
int		parse_sphere(t_data *data, char **tokens, int id);
int 	parse_plane(t_data *data, char **tokens, int id);
int 	parse_cylinder(t_data *data, char **tokens, int id);
void	cnt_unique_id(int id, int *arr);
void	print_a_light(t_data data);
void	print_light(t_data data);
void	print_cam(t_data data);
void	print_sph(t_obj *obj);
void	print_pl(t_obj *obj);
void	print_cyl(t_obj *obj);
void	print_obj(t_obj *obj);
void	print_data(t_data data);
t_obj	*lst_new(int id);
void	lst_addback(t_obj **head, t_obj *new);

# endif
