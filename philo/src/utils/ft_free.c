/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:04:51 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/05 19:31:29 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	ft_join(t_table *table)
{
	t_philo	*philo;

	philo = table->philo;
	while (1)
	{
		pthread_join(philo->philos, NULL);
		if (philo->last == 1)
			break ;
		philo = philo->next;
	}
}

static void	ft_free_fork(t_table *table)
{
	t_philo	*philo;

	philo = table->philo;
	while (1)
	{
		pthread_mutex_destroy(philo->fork);
		free(philo->fork);
		if (philo->last == 1)
			break ;
		philo = philo->next;
	}
}

static void	ft_free_lst(t_philo *philo)
{
	t_philo	*tmp;

	while (philo->last != 1)
	{
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
	free(philo);
}

void	ft_free(t_table **table)
{
	ft_join((*table));
	pthread_join((*table)->server->monitor, NULL);
	ft_free_fork((*table));
	ft_free_lst((*table)->philo);
	free((*table)->server);
	pthread_mutex_destroy(&(*table)->infos->print_mutex);
	pthread_mutex_destroy(&(*table)->infos->data_mutex);
	free((*table)->infos);
	free((*table));
}
