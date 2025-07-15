/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 06:57:56 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/15 17:37:46 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

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
int			ft_atoi(const char *str);
void		ft_putstr(char *s);
char		*ft_strdup(const char *s);
void		*ft_calloc(size_t count, size_t size);

// src functions
int			filter_input(int ac, char **av);
t_table		*init_table(t_table *table, int ac, char **av);
t_philos	*init_philos(t_table *table);
void		*philo_simulation(void *data);
void		philo_routine(t_philos *philo);
long		get_current_time(void);
void		taking_fork(t_philos *philo);
void		display_log(t_philos *philo, char *str);
void		eating(t_philos *philo);
void		ft_usleep(size_t ms);
void		sleeping(t_philos *philo);
void		thinking(t_philos *philo);
void		*monitor_routine(void *data);
void		cleanup(t_table *table, t_philos *philos);
void		cleanup_mutex_init(t_table *table, size_t forks_count);
int			check_philo_death(t_table *table);
int			check_nbr_of_meals(t_table *table);
int			create_threads(t_philos *philo, t_table *table);
int			ft_isdigit(char *str);
void		init_left_right_fork(size_t i, t_table *table, t_philos *philo);
int			check_death(t_table *table);
void		leak_prevention(t_philos *philo, t_table *table, size_t failed_i);

#endif
