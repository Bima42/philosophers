#include "philosophers.h"

int	str_error(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

int	check_arg(int argc, char **argv, t_data *data)
{
	if (argc != 6)
		return (0);
	init_data(data, argv);
	if (data->time_to_die < 0 && data->time_to_sleep < 0 && data->time_to_eat < 0)
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
