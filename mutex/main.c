#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	long		nb;

	nb = 0;
	if (!check_arg(argc, argv, &data))
		return (str_error("Error arguments\n", 1));
	if (!init_mutex(&data))
		return (str_error("Init mutex failed\n", 1)); //check for free, destroy mutex etc
	return (0);
}
