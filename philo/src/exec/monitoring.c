/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:16:53 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/05 20:02:27 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_death(t_philo *philos)
{
	pthread_mutex_lock(&philos->infos->data_mutex);
	if ((actual_time() - philos->infos->start_time)
		- philos->last_meal >= philos->infos->t_die)
	{
		if (philos->infos->end_of_simulation != 1)
		{
			philos->status = DEAD;
			philos->infos->end_of_simulation = 1;
			pthread_mutex_unlock(&philos->infos->data_mutex);
			print_status(philos);
			return (END_OF_SIMULATION);
		}
	}
	pthread_mutex_unlock(&philos->infos->data_mutex);
	return (SUCCESS);
}

int	check_fullness(t_philo *philos)
{
	pthread_mutex_lock(&philos->infos->data_mutex);
	if (philos->is_full == true && philos->check == false)
	{
		philos->check = true;
		philos->infos->counter++;
		if (philos->infos->counter >= philos->infos->nb_philo)
		{
			philos->infos->end_of_simulation = 1;
			pthread_mutex_unlock(&philos->infos->data_mutex);
			return (END_OF_SIMULATION);
		}
	}
	pthread_mutex_unlock(&philos->infos->data_mutex);
	return (SUCCESS);
}

int	check_end_simulation(t_philo *philos)
{
	pthread_mutex_lock(&philos->infos->data_mutex);
	if (philos->infos->end_of_simulation == 1)
	{
		pthread_mutex_unlock(&philos->infos->data_mutex);
		return (END_OF_SIMULATION);
	}
	pthread_mutex_unlock(&philos->infos->data_mutex);
	return (SUCCESS);
}
