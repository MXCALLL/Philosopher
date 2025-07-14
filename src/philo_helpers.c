/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:23:53 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/14 16:23:53 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_left_right_fork(size_t i, t_table *table, t_philos *philo)
{
	if (i == table->num_philos - 1)
	{
		philo[i].left_fork = &table->forks[0];
		philo[i].right_fork = &table->forks[i];
	}
	else
	{
		philo[i].left_fork = &table->forks[i];
		philo[i].right_fork = &table->forks[i + 1];
	}
}

void	display_log(t_philos *philo, char *str)
{
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->someone_died)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->table->death_mutex);
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%zu %zu %s\n", get_current_time() - philo->table->start_time_ms,
		philo->id, str);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	leak_prevention(t_philos *philo, t_table *table, size_t failed_i)
{
	size_t	i;

	pthread_mutex_lock(&table->death_mutex);
	table->someone_died = 1;
	pthread_mutex_unlock(&table->death_mutex);
	i = 0;
	while (i < failed_i)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
