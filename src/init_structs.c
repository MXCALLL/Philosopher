/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:36:58 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/15 18:01:09 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	cleanup_mutex_init(t_table *table, size_t forks_count)
{
	size_t	i;

	if (table && table->forks)
	{
		i = 0;
		while (i < forks_count)
			pthread_mutex_destroy(&table->forks[i++]);
	}
}

int	init_mutex_table(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->num_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (cleanup_mutex_init(table, i), 1);
		i++;
	}
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (cleanup_mutex_init(table, i), 1);
	if (pthread_mutex_init(&table->death_mutex, NULL))
	{
		cleanup_mutex_init(table, i);
		return (pthread_mutex_destroy(&table->print_mutex), 1);
	}
	if (pthread_mutex_init(&table->meal_mutex, NULL))
	{
		cleanup_mutex_init(table, i);
		pthread_mutex_destroy(&table->print_mutex);
		return (pthread_mutex_destroy(&table->death_mutex), 1);
	}
	return (0);
}

t_table	*init_table(t_table *table, int ac, char **av)
{
	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		return (ft_putstr("Malloc fails"), NULL);
	table->meals_per_philo = 0;
	table->someone_died = 0;
	table->all_ate_enough = 0;
	table->num_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->meals_per_philo = ft_atoi(av[5]);
	if (!table->num_philos || !table->time_to_die || !table->time_to_eat
		|| !table->time_to_sleep)
		return (free(table), NULL);
	table->forks = ft_calloc(table->num_philos, sizeof(pthread_mutex_t));
	if (!table->forks)
		return (free(table), ft_putstr("malloc forks fail"), NULL);
	if (init_mutex_table(table))
		return (free(table->forks), free(table), NULL);
	table->start_time_ms = get_current_time();
	return (table);
}

t_philos	*init_philos(t_table *table)
{
	t_philos	*philo;
	size_t		i;

	philo = ft_calloc(table->num_philos, sizeof(t_philos));
	if (!philo)
		return (ft_putstr("Malloc fails"), NULL);
	table->philos = philo;
	i = 0;
	while (i < table->num_philos)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal_timing = get_current_time();
		init_left_right_fork(i, table, philo);
		philo[i].table = table;
		i++;
	}
	return (philo);
}
