/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:42:13 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/05 22:23:12 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str || !fd)
		return (-1);
	while (*str != 0)
		i += write(fd, str++, 1);
	return (i);
}


int	print_error(char *str)
{
	ft_putstr_fd(RED "Error :" RESET " ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (FAILURE);
}
