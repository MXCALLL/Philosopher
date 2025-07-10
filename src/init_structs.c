/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:36:58 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/10 19:41:58 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long get_current_time(void)
{
	struct timeval start;

	if (gettimeofday(&start, NULL))
		ft_putstr("get time failed");

	return (start.tv_sec * 1000 + start.tv_usec / 1000);
}

t_table	*init_table(t_table *table, int ac, char **av)
{
	size_t		i;

	table = ft_calloc(1, sizeof(t_table));
	if(!table)
		return(ft_putstr("Malloc fails"), NULL);
	table->meals_per_philo = 0;
	table->someone_died = 0;
	table->num_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->meals_per_philo = ft_atoi(av[5]);
	if (!table->num_philos || !table->time_to_die
		|| !table->time_to_eat || !table->time_to_sleep)
			return (free(table), NULL);
	table->forks = ft_calloc(table->num_philos, sizeof(pthread_mutex_t));
	if (!table->forks)
		return (free(table), ft_putstr("malloc forks fail"), NULL);
	i = 0;
	while(i < table->num_philos)
		pthread_mutex_init(&table->forks[i++], NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	pthread_mutex_init(&table->death_mutex, NULL);
	pthread_mutex_init(&table->meal_mutex, NULL);
	table->start_time_ms = get_current_time();
	return (table);
}

t_philos	*init_philos_monitor(t_table *table)
{
	t_philos	*philo;
	pthread_t	monitor;
	size_t		i;
	int			status;

	philo = ft_calloc(table->num_philos, sizeof(t_philos));
	if (!philo)
		return(ft_putstr("Malloc fails"), NULL);
	table->philos = philo;
	i = 0;
	while (i < table->num_philos)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal_timing = get_current_time();
		philo[i].left_fork = &table->forks[i];
		philo[i].right_fork = &table->forks[(i + 1) % table->num_philos];
		philo[i].table = table;
		status = pthread_create(&philo[i].thread, NULL, philo_simulation, &philo[i]);
		if (status != 0)
			return (ft_putstr("failed creating threads"), free(philo), NULL);
		i++;
	}

	status = pthread_create(&monitor, NULL, monitor_routine, table);
	if (status != 0)
		return (ft_putstr("failed creating threads"), free(philo), NULL);

	if (pthread_join(monitor, NULL) != 0)
			return (ft_putstr("monitor join failed"), NULL);
	i = 0;
	while (i < table->num_philos)
		if (pthread_join(philo[i++].thread, NULL) != 0)
			return (ft_putstr("pthread join failed"), NULL);
	return (philo);
}
