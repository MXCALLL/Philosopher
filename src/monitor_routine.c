/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:02:03 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/11 16:07:15 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitor_routine(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (1)
	{
		if (check_philo_death(table))
			return (NULL);
		if (check_nbr_of_meals(table))
			return (NULL);
		ft_usleep(1);
	}
	return (NULL);
}

int	check_philo_death(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->meal_mutex);
		if (get_current_time()
			- table->philos[i].last_meal_timing > (long)table->time_to_die)
		{
			pthread_mutex_unlock(&table->meal_mutex);
			pthread_mutex_lock(&table->death_mutex);
			table->someone_died = 1;
			pthread_mutex_unlock(&table->death_mutex);
			pthread_mutex_lock(&table->print_mutex);
			printf("%zu %zu died\n", get_current_time() - table->start_time_ms,
				table->philos[i].id);
			pthread_mutex_unlock(&table->print_mutex);
			return (1);
		}
		pthread_mutex_unlock(&table->meal_mutex);
		i++;
	}
	return (0);
}

int	check_nbr_of_meals(t_table *table)
{
	size_t	i;
	size_t	satisfied_philos;

	if (table->meals_per_philo > 0)
	{
		satisfied_philos = 0;
		i = 0;
		while (i < table->num_philos)
		{
			pthread_mutex_lock(&table->meal_mutex);
			if (table->philos[i].meals_eaten >= table->meals_per_philo)
				satisfied_philos++;
			pthread_mutex_unlock(&table->meal_mutex);
			i++;
		}
		if (satisfied_philos == table->num_philos)
			return (1);
	}
	return (0);
}
