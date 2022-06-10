#include <minirt.h>

int main(int ac, char **av)
{
	t_data	data;

	if (!check_arg(ac))
		return (print_error("Error\n", 1));
	if (!rt_read(av[1], &data))
		return (print_error("Error\n", 1));
	print_data(data);
}
