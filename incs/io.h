#ifndef IO_H
# define IO_H

int		rt_read(char *filename, t_data *data);
int		double_arr_free(void **content);
int		parse(int fd, t_data *data);
int		get_token_len(char **tokens);
int		print_error(char *err_str, int err_num);
void	convert_line(char *line);
int		parse_sphere(t_data *data, char **tokens);
int 	parse_plane(t_data *data, char **tokens);
int 	parse_cylinder(t_data *data, char **tokens);

# endif
