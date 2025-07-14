/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:07:13 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/14 12:54:45 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(size_t ms)
{
	size_t	current;

	current = get_current_time();
	while (get_current_time() - current < ms)
		usleep(500);
}

void	*philo_simulation(void *data)
{
	t_philos	*philo;

	philo = (t_philos *)data;
	if (philo->id % 2 == 1)
		ft_usleep(1);
	philo_routine(philo);
	return (NULL);
}

int	check_all_ate_enough_meals(t_table *table)
{
	pthread_mutex_lock(&table->death_mutex);
	if (table->all_ate_enough)
	{
		pthread_mutex_unlock(&table->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->death_mutex);
	return (0);
}

void	philo_routine(t_philos *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->table->death_mutex);
		if (philo->table->someone_died)
		{
			pthread_mutex_unlock(&philo->table->death_mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->table->death_mutex);
		if (philo->table->meals_per_philo > 0
			&& philo->meals_eaten >= philo->table->meals_per_philo)
			return ;
		taking_fork(philo);
		eating(philo);
		if (check_all_ate_enough_meals(philo->table))
			break ;
		sleeping(philo);
		thinking(philo);
	}
}

void	cleanup(t_table *table, t_philos *philos)
{
	size_t	i;

	if (table)
	{
		if (table->forks)
		{
			i = 0;
			while (i < table->num_philos)
				pthread_mutex_destroy(&table->forks[i++]);
			free(table->forks);
		}
		pthread_mutex_destroy(&table->print_mutex);
		pthread_mutex_destroy(&table->death_mutex);
		pthread_mutex_destroy(&table->meal_mutex);
		free(table);
	}
	if (philos)
		free(philos);
}
