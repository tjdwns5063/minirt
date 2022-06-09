#include "minirt.h"

int	rt_read(char *filename, t_data *data)
{
	int		fd; 
	
	if (!check_ext(filename))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	parse(fd, data);
	printf("%f\n", data->a_light.light_ratio);
	close(fd);
	//check_range
	// if (!check_data(datas))
	// 	arr_free_and_error((void **)datas);
	// ret = (double **)malloc(sizeof(double *) * (len + 1));
	// if (!ret)
	// 	arr_free_and_error((void **)datas);
	// ret[len] = 0;
	// while (--len >= 0)
	// 	ret[len] = convert_data(datas[len]);
	// double_arr_free((void **)datas);
	return (1);
}