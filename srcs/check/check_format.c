#include "minirt.h"

int	check_id_cnt(int *arr)
{
	return (arr[0] == 1 && arr[1] == 1 && arr[2] == 1);
}

static int	check_short_format(char *line)
{
	int	dot_cnt;
	int	idx;

	idx = 0;
	dot_cnt = 0;
	if (line[idx] && (line[idx] == '+' || line[idx] == '-'))
		idx++;
	while (line[idx] && (('0' <= line[idx] && line[idx] <= '9') || line[idx] == '.'))
	{
		if (line[idx] == '.')
			dot_cnt++;
		if (('0' > line[idx] || line[idx] > '9') && line[idx] != '.')
			return (1);
		if (dot_cnt > 1)
			return (1);
		idx++;
	}
	if (line[idx] != 0)
		return (1);
	return (0);
}

static int	check_long_format(char *line)
{
	int	idx;
	int	ret;
	char	**tokens;

	idx = 0;
	while (line[idx])
	{
		if (line[idx] == ',' && line[idx + 1] == ',')
			return (1);
		idx++;
	}
	idx = -1;
	ret = 0;
	tokens = ft_split(line, ',');
	while (tokens[++idx])
	{
		if (check_short_format(tokens[idx]))
		{
			double_arr_free((void **)tokens);
			return (1);
		}
		ret++;
	}
	double_arr_free((void **)tokens);
	if (ret != 3)
		return (1);
	return (0);
}

static int	check_nums(char **tokens, int flag)
{
	int	ret;
	int	size;
	int	idx;

	ret = 0;
	size = get_token_len(tokens);
	idx = 1;
	ret += check_token_size(tokens, flag);
	while (idx < size)
	{
		if ((1 << (idx - 1)) & flag)
			ret += check_long_format(tokens[idx]);
		else
			ret += check_short_format(tokens[idx]);
		idx++;
	}
	if (ret == 0)
		return (flag);
	return (0);
}

int	check_format(char *line)
{
	int			id;
	int			ret;
	char		**tokens;

	tokens = ft_split(line, ' ');
	id = check_id(tokens);
	ret = 1;
	ret = check_nums(tokens, id);
	double_arr_free((void **)tokens);
	return (ret);
}
