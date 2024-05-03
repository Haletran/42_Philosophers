/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:25:33 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/03 17:48:48 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_status(t_philo *philos)
{
	if (philos->status == EATING && philos->infos->end_of_simulation != 1)
		printf("%ld %d " YELLOW "is eating\n" RESET, actual_time()
			- philos->infos->start_time, philos->id);
	else if (philos->status == SLEEPING && philos->infos->end_of_simulation != 1)
		printf("%ld %d " GREEN "is sleeping\n" RESET, actual_time()
			- philos->infos->start_time, philos->id);
	else if (philos->status == THINKING && philos->infos->end_of_simulation != 1)
		printf("%ld %d " CYAN "is thinking\n" RESET, actual_time()
			- philos->infos->start_time, philos->id);
	else if (philos->status == DEAD && philos->infos->end_of_simulation == 1)
		printf("%ld %d " RED "died\n" RESET, actual_time()
			- philos->infos->start_time, philos->id);
}

int	print_forks(t_philo *philos)
{
	pthread_mutex_lock(&philos->infos->print_mutex);
	if (philos->infos->end_of_simulation == 1)
	{
		pthread_mutex_unlock(&philos->infos->print_mutex);
		pthread_mutex_unlock(philos->fork);
		return (END_OF_SIMULATION);
	}
	printf("%ld %d has taken a fork\n", actual_time()
		- philos->infos->start_time, philos->id);
	pthread_mutex_unlock(&philos->infos->print_mutex);
	return (SUCCESS);
}
