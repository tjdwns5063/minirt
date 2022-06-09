#include "minirt.h"

int	check_empty_line(char *line)
{
	return (ft_strncmp(line, "", 1) == 0);
}

int	check_arg(int ac)
{
	return (ac == 2);
}

int	check_id(char **token)
{
	if (ft_strncmp(token[0], "A", 1) == 0)
		return (A);
	if (ft_strncmp(token[0], "C", 1) == 0)
		return (C);
	if (ft_strncmp(token[0], "L", 1) == 0)
		return (L);
	if (ft_strncmp(token[0], "sp", 2) == 0)
		return (SP);
	if (ft_strncmp(token[0], "pl", 2) == 0)
		return (PL);
	if (ft_strncmp(token[0], "cy", 2) == 0)
		return (CY);
	return (0);
}

int	check_token_size(char **tokens, int id)
{
	int	idx;
	int size;

	idx = -1;
	size = -1;
	while (tokens[++idx])
		++size;
	if (id == A && size != 2)
		return (1);
	if (id == C && size != 3)
		return (1);
	if (id == L && size != 3)
		return (1);
	if (id == PL && size != 3)
		return (1);
	if (id == SP && size != 3)
		return (1);
	if (id == CY && size != 5)
		return (1);
	if (id == -1)
		return (1);
	return (0);
}

int	check_ext(char *filename)
{
	char	*tmp;
	int		ret;

	tmp = filename;
	while (*tmp)
		tmp++;
	ret = ft_strncmp(tmp - 3, ".rt", 3);
	return (ret == 0);
}
