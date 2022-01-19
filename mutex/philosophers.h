#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				count_meal;
	struct s_data	*data;
	pthread_mutex_t	mutex_id;
}				t_philo;

typedef struct	s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_to_eat;
	int				dead;
	pthread_mutex_t	forks[250]; //TODO : try to use pointer an malloc	
	pthread_mutex_t	message;
	t_philo			philo[250]; //TODO : try to use pointer an malloc
}				t_data;

//Error
int	str_error(char *str, int ret);
int	check_arg(int argc, char **argv, t_data *data);
int	ft_strlen(char *str);

//Init
void	init_data(t_data *data, int argc, char **argv);
int		init_mutex(t_data *data);
int		init_philo(t_data *data);
int		ft_atoi(const char *nptr);

#endif
