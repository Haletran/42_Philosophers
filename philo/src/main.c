/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:01:38 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/05 22:20:49 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc > 6 || argc < 5)
		return (print_error("Invalid number of arguments"));
	table = init_table(argv, table);
	if (table == NULL)
		return (print_error("Invalid arguments"));
	if (setup_philo(table) == FAILURE)
		return (print_error("Philos setup failed"));
	ft_free(&table);
	return (0);
}
