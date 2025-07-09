/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:07:13 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/09 19:04:35 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(size_t ms)
{
	size_t current;

	current = get_current_time();
	while (get_current_time() - current < ms)
		usleep(500);
}

void display_log(t_philos *philo, char *str)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%zu %zu %s\n", get_current_time() - philo->table->start_time_ms, philo->id, str);	
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	*philo_simulation(void *data)
{
	t_philos *philo;

	philo = (t_philos *)data;

	if (philo->table->num_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		display_log(philo, "has taken a fork");
		ft_usleep(philo->table->time_to_die);
		display_log(philo, "died");
		return (NULL);
	}
	if (philo->id % 2)
	{
		ft_usleep(philo->table->time_to_eat);
	}
	// philo routine
	philo_routine(philo);
	return (NULL);
}

void	philo_routine(t_philos *philo)
{
	while (1)
	{
		if (philo->table->someone_died ||(philo->table->meals_per_philo > 0 && philo->meals_eaten >= philo->table->meals_per_philo))
			return ;
		if (philo->meals_eaten && philo->meals_eaten == philo->table->meals_per_philo)
			return ;
		taking_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

void	*monitor_routine(void *data)
{
	t_table *table;

	table = (t_philos *)data;






	return (NULL);
}
