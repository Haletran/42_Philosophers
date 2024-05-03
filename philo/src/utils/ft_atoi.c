/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:27:19 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/24 17:29:17 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_atoi(const char *str)
{
	int	int_dest;
	int	sign;

	sign = 1;
	int_dest = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str != 0)
	{
		if (*str > 47 && *str < 58)
			int_dest = int_dest * 10 + (*str - 48);
		else
			return (int_dest * sign);
		str++;
	}
	return (int_dest * sign);
}
