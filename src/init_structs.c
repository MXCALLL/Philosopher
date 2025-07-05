/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:36:58 by muidbell          #+#    #+#             */
/*   Updated: 2025/06/14 20:09:20 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philos *initialize_structs(int ac, char **av)
{
	t_table		*table;
	t_philos	*philo;
	size_t		i;

	table = malloc(sizeof(t_table));

	table = (t_table *)malloc(sizeof(t_table *));
	if(!table)
		return(ft_putstr("Malloc fail"), NULL);

	table->meals_per_philo = 0;
	table->someone_died = 0;
	table->num_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 7)
		table->meals_per_philo = ft_atoi(av[5]);
	if (!table->num_philos || !table->time_to_die
		|| !table->time_to_eat || !table->time_to_sleep)
			return (free(table), NULL);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (!table->forks)
		return (free(table), ft_putstr("malloc forks fail"), NULL);

	while(i < table->num_philos)
		pthread_mutex_init(&table->forks[i], NULL);
	pthread_mutex_init(&table->print_mutex, NULL);

	// table->start_time_ms = gettimeofday();
}
