#include "minirt.h"

int	print_error(char *err_str, int err_num)
{
	write(2, err_str, ft_strlen(err_str));
	return (err_num);
}

int	double_arr_free(void **content)
{
	int	idx;

	if (!content)
		return (0);
	idx = -1;
	while (content[++idx])
		free(content[idx]);
	free(content);
	return (0);
}

int	get_token_len(char **tokens)
{
	int	idx;

	idx = -1;
	while (tokens[++idx])
		;
	return (idx);
}

void	convert_line(char *line)
{
	int	idx;

	idx = -1;
	while (line[++idx])
	{
		if (line[idx] == ',')
			line[idx] = ' ';
	}
}

void	cnt_unique_id(int id, int *arr)
{
	if (id == A)
		arr[0] += 1;
	if (id == C)
		arr[1] += 1;
	if (id == L)
		arr[2] += 1;
}