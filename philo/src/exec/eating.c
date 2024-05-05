/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:42:28 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/05 14:49:27 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_end_of_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->infos->data_mutex);
	if (philo->infos->end_of_simulation == 1 || philo->status == DEAD)
	{
		pthread_mutex_unlock(&philo->infos->data_mutex);
		pthread_mutex_unlock(philo->fork);
		return (END_OF_SIMULATION);
	}
	pthread_mutex_unlock(&philo->infos->data_mutex);
	return (SUCCESS);
}

void	print_fork_taken(t_philo *philo)
{
	pthread_mutex_lock(&philo->infos->print_mutex);
	printf("%ld %d has taken a fork\n", actual_time()
		- philo->infos->start_time, philo->id);
	pthread_mutex_unlock(&philo->infos->print_mutex);
}

int	check_single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->infos->data_mutex);
	if (philo->infos->nb_philo == 1)
	{
		pthread_mutex_unlock(philo->fork);
		pthread_mutex_unlock(&philo->infos->data_mutex);
		return (END_OF_SIMULATION);
	}
	pthread_mutex_unlock(&philo->infos->data_mutex);
	return (SUCCESS);
}

void	update_eating_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->infos->data_mutex);
	philo->status = EATING;
	philo->eat_count++;
	philo->last_meal = actual_time() - philo->infos->start_time;
	if (philo->eat_count == philo->infos->nb_meals)
		philo->is_full = true;
	print_status(philo);
	pthread_mutex_unlock(&philo->infos->data_mutex);
}
