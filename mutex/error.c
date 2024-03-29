/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <tpauvret@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:50 by tpauvret          #+#    #+#             */
/*   Updated: 2022/01/21 16:26:22 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	str_error(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

int	arg_error(t_data *data)
{
	if (data->time_to_die < 50 || data->time_to_sleep < 50
		|| data->time_to_eat < 50 || data->nb_philo < 1)
		return (0);
	return (1);
}

int	check_arg(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (0);
	init_data(data, argc, argv);
	if (!arg_error(data))
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
