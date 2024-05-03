/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:14:13 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/25 20:18:32 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

t_philo	*init_stack(t_philo *a, int nb_philo, t_table *table)
{
	t_philo	*start;
	int		id;

	start = NULL;
	id = 1;
	while (id <= nb_philo)
	{
		if (!a)
		{
			a = ft_lst_new(id, table);
			start = a;
		}
		else
			a = ft_lstadd_back(a, id, table);
		id++;
	}
	a->next = start;
	a = start;
	return (a);
}

void	*setup_infos(t_table *table, char **argv)
{
	table->infos = ft_calloc(1, sizeof(t_infos));
	if (!table->infos)
		return (NULL);
	table->infos->nb_philo = ft_atoi(argv[1]);
	if (table->infos->nb_philo >= 500)
		return (NULL);
	table->infos->start_time = actual_time();
	table->infos->t_die = ft_atoi(argv[2]);
	table->infos->t_eat = ft_atoi(argv[3]);
	table->infos->t_sleep = ft_atoi(argv[4]);
	table->infos->counter = 0;
	pthread_mutex_init(&table->infos->print_mutex, NULL);
	if (argv[5])
		table->infos->nb_meals = ft_atoi(argv[5]);
	return (table);
}

void	*init_table(char **argv, t_table *table)
{
	if (parse_input(argv) == FAILURE)
		return (NULL);
	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		return (NULL);
	if (setup_infos(table, argv) == NULL)
		return (NULL);
	table->philo = init_stack(table->philo, table->infos->nb_philo, table);
	table->server = ft_calloc(1, sizeof(t_monitor));
	if (!table->server)
		return (NULL);
	table->server->nb_meals = 0;
	table->server->monitor = 0;
	return (table);
}

int	parse_input(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == FAILURE)
				return (FAILURE);
			if (str[i][j] == '-' && j != 0)
				return (FAILURE);
			j++;
		}
		if (ft_atoi(str[i]) <= 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
