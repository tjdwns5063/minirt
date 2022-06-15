#include "minirt.h"

int	check_root(double root, t_hit_record *record)
{
	return (record->t_min <= root && root <= record->t_max);
}

int	check_discrim(double discrim, double a, double b, t_hit_record *record)
{
	double	root;

	if (discrim < 0)
		return (0);
	root = (-b - sqrt(discrim)) / a;
	if (check_root(root, record))
		return (-1);
	root = (-b + sqrt(discrim)) / a;
	if (check_root(root, record))
		return (1);
	return (0);
}
