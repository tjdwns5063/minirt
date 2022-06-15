#ifndef CHECK_H
# define CHECK_H

int			check_empty_line(char *line);
int			check_format(char *line);
int			check_arg(int ac);
int			check_token_size(char **tokens, int id);
int			check_id(char **token);
int			check_ext(char *filename);
int			check_id_cnt(int *arr);
int			check_data(t_data *data);
int			check_discrim(double discrim, double a, double b, t_hit_record *record);

# endif
