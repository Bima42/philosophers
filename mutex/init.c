/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <tpauvret@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:36 by tpauvret          #+#    #+#             */
/*   Updated: 2022/06/23 12:04:37 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_data *data, int argc, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meal_to_eat = ft_atoi(argv[5]);
	else
		data->meal_to_eat = -1;
	data->dead = 0;
	data->end = 0;
}

int	free_mutex(int i, int ret, t_data *data)
{
	if (i == 0)
		return (ret);
	else
		while (i != -1)
			pthread_mutex_destroy(&(data->forks[i--]));
	return (ret);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (free_mutex(i, 0, data));
	}
	if (pthread_mutex_init(&(data->message), NULL))
		return (0);
	if (pthread_mutex_init(&(data->is_eating), NULL))
		return (0);
	return (init_philo(data));
}

int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].id = i;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->nb_philo;
		data->philo[i].count_meal = 0;
		data->philo[i].death_timer = 0;
		data->philo[i].data = data;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	count;
	int	res;

	sign = 1;
	count = 0;
	res = 0;
	while (nptr[count] == ' ' || (nptr[count] >= 9 && nptr[count] <= 13))
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign = sign * -1;
		count++;
	}
	while (nptr[count] >= '0' && nptr[count] <= '9')
	{
		res = res * 10 + nptr[count] - '0';
		count++;
	}
	return (res * sign);
}
