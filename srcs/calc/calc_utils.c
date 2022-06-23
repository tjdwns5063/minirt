#include "minirt.h"

double  degrees_to_radians(double degree)
{
    return (degree * (M_PI / 180));
}

double  rt_abs(double d)
{
    if (d < 0.)
        return (d * -1.);
    return (d);
}
