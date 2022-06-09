#ifndef CHECK_H
# define CHECK_H

int			check_empty_line(char *line);
static int	check_short_format(char *line);
static int	check_long_format(char *line);
static int	check_nums(char **tokens, int flag);
int			check_format(char *line);
int			check_arg(int ac);
int			check_token_size(char **tokens, int id);
int			check_id(char **token);
int			check_ext(char *filename);

# endif
