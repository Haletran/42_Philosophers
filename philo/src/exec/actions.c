/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:16:59 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/03 19:23:20 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	if (check_end_of_simulation(philo) == END_OF_SIMULATION)
		return (END_OF_SIMULATION);
	print_fork_taken(philo);
	if (check_single_philo(philo) == END_OF_SIMULATION)
		return (END_OF_SIMULATION);
	pthread_mutex_lock(philo->next->fork);
	if (check_end_of_simulation(philo) == END_OF_SIMULATION)
	{
		pthread_mutex_unlock(philo->next->fork);
		return (END_OF_SIMULATION);
	}
	print_fork_taken(philo);
	if (check_end_of_simulation(philo) == END_OF_SIMULATION)
	{
		pthread_mutex_unlock(philo->next->fork);
		return (END_OF_SIMULATION);
	}
	update_eating_status(philo);
	ft_usleep(philo->infos->t_eat);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->next->fork);
	return (SUCCESS);
}

int	is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->infos->print_mutex);
	if (philo->infos->end_of_simulation == 1)
	{
		pthread_mutex_unlock(&philo->infos->print_mutex);
		return (END_OF_SIMULATION);
	}
	philo->status = THINKING;
	print_status(philo);
	pthread_mutex_unlock(&philo->infos->print_mutex);
	return (SUCCESS);
}

int	is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->infos->print_mutex);
	if (philo->infos->end_of_simulation == 1)
	{
		pthread_mutex_unlock(&philo->infos->print_mutex);
		return (END_OF_SIMULATION);
	}
	philo->status = SLEEPING;
	print_status(philo);
	pthread_mutex_unlock(&philo->infos->print_mutex);
	ft_usleep(philo->infos->t_sleep);
	return (SUCCESS);
}
