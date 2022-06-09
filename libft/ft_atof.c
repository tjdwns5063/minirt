#include "libft.h"

static int	get_sign(char **str)
{
	int	sign;

	sign = 1;
	while (*str && ((9 <= **str && **str <= 13) || **str == ' '))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

static int	get_integer(char **str)
{
	int	integer;

	integer = 0;
	while (**str && ('0' <= **str && **str <= '9'))
	{
		integer *= 10;
		integer += **str - '0';
		(*str)++;
	}
	return (integer);
}

double	ft_atof(char *str)
{
	int sign;
	int integer;
	double	ret;
	double	real;

	sign = get_sign(&str);
	ret = 0.0;
	integer = get_integer(&str);
	real = 1.0;
	if (*str && *str == '.')
		str++;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		integer *= 10;
		integer += (*str - '0');
		real *= 10; 
		str++;
	}
	ret = (integer * (1 / real)) * sign;
	return (ret);
}
