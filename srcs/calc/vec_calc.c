#include "minirt.h"

double	v_length(double *vec)
{
	double	len;

	len = sqrt((vec[0] * vec[0]) + (vec[1] * vec[1]) + (vec[2] * vec[2]));
	return (len);
}
