#include "minirt.h"

int	parse(int fd, t_data *data)
{
	char		*line;
	int			id;
	static int	id_cnt[3];

	while (get_next_line(fd, &line))
	{
		if (!check_empty_line(line))
		{
			id = check_format(line);
			if (id)
			{
				cnt_unique_id(id, id_cnt);
				if (!parse_data(data, line, id))
				{
					free(line);
					return (0);
				}
			}
		}
		free(line);
	}
	free(line);
	if (!check_id_cnt(id_cnt))
		return (0);
	return (1);
}

int	rt_read(char *filename, t_data *data)
{
	int		fd; 
	
	if (!check_ext(filename))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	data->objs = 0;
	if (!parse(fd, data))
		return (0);
	close(fd);
	if (!check_data(data))
		return (0);
	return (1);
}