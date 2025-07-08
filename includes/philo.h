/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 06:57:56 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/08 12:28:03 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct s_table
{
	size_t				num_philos;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				meals_per_philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		meal_mutex;
	int					someone_died;
	int					all_ate_enough;
	long				start_time_ms;
	struct s_philos		*philos;
}	t_table;

typedef struct s_philos
{
	size_t				id;
	size_t				meals_eaten;
	long				last_meal_timing;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_table				*table;
}	t_philos;


// helper functions
int		ft_atoi(const char *str);
void	ft_putstr(char *s);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t count, size_t size);

// parsing functions
int	filter_input(int ac, char **av);

// src functions
t_table		*init_table(t_table *table, int ac, char **av);
t_philos	*init_philos(t_table *table);
void		*philo_simulation(void *data);

#endif
