/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:01:13 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/05 19:11:40 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "colors.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define SUCCESS 0
# define FAILURE 1
# define END_OF_SIMULATION 2

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}						t_status;

typedef struct s_philo
{
	int					id;
	int					time;
	long int			last_meal;
	int					eat_count;
	int					last;
	t_status			status;
	bool				is_full;
	bool				check;
	pthread_mutex_t		*fork;
	pthread_t			philos;
	struct s_infos		*infos;
	struct s_philo		*next;
	struct s_philo		*prev;
}						t_philo;

typedef struct s_monitor
{
	int					nb_meals;
	pthread_t			monitor;
}						t_monitor;

typedef struct s_infos
{
	long int			start_time;
	int					nb_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					nb_meals;
	int					counter;
	int					end_of_simulation;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		data_mutex;
}						t_infos;

typedef struct s_table
{
	struct s_infos		*infos;
	struct s_philo		*philo;
	struct s_monitor	*server;
}						t_table;

/*EXEC*/
void					*init_table(char **argv, t_table *table);
t_philo					*init_stack(t_philo *a, int nb_philo, t_table *table);
int						parse_input(char **argv);
int						setup_philo(t_table *table);
void					print_status(t_philo *philos);
void					ft_join_server(t_table *table);
int						check_end_simulation(t_philo *philos);
int						check_fullness(t_philo *philos);
int						check_death(t_philo *philos);
int						print_forks(t_philo *philos);
int						check_end_of_simulation(t_philo *philo);
void					print_fork_taken(t_philo *philo);
int						check_single_philo(t_philo *philo);
void					update_eating_status(t_philo *philo);

/*LIB*/
int						ft_isdigit(int c);
int						ft_atoi(const char *str);
int						print_error(char *str);
void					*ft_calloc(size_t elementCount, size_t elementSize);
void					ft_free(t_table **table);
int						ft_strlen(char *str);

/*LST*/
void					*ft_lst_new(int content, t_table *table);
t_philo					*ft_lstadd_back(t_philo *lst, int value,
							t_table *table);

/*ACTIONS*/
int						is_thinking(t_philo *philo);
int						is_eating(t_philo *philo);
int						is_sleeping(t_philo *philo);
void					ft_usleep(long int time_in_ms);
long int				actual_time(void);

#endif