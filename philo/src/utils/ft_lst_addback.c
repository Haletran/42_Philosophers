/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:44:04 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/24 17:29:37 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

t_philo	*ft_lstadd_back(t_philo *lst, int value, t_table *table)
{
	t_philo	*tmp;

	if (lst == NULL)
	{
		lst = ft_lst_new(value, table);
		return (lst);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	tmp = lst;
	lst->prev = tmp;
	lst->prev->last = 0;
	lst->next = ft_lst_new(value, table);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	tmp = lst;
	lst->prev = tmp;
	return (lst);
}
