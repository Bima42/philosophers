#include "philosophers.h"

int	ft_atoi(const char *nptr);

void	*routine(void *threadid)
{
	long tid;
    tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid);
	return (0);
//    pthread_exit(NULL);
}

int	main(int argc, char **argv)
{
//	pthread_t	philo[4];
	t_data		data;
//	long		nb;
//	int			ret;

//	nb = 0;

	if (!check_arg(argc, argv, &data))
		return (str_error("Error arguments\n", 1));
/*	while (nb < 5)
	{
		write(1, "Creating threads ...\n", 22);
		ret = pthread_create(&philo[nb], NULL, routine, (void *)nb);
		usleep(100);
		if (ret)
		{
			write(1, "Creation failed\n", 17);
			exit(0);
		}
		nb++;
	}*/
	printf("Arg 1 : %d\nArg 2 : %d\nArg 3 : %d\nArg 4 : %d\nArg 5 : %d\n", data.nb_philo, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.meal_to_eat);
	return (0);
}