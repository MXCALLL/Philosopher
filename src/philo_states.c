/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:13:12 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/15 16:53:18 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	taking_fork(t_philos *philo)
{
	if (philo->table->num_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		display_log(philo, "has taken a fork");
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		display_log(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		display_log(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		display_log(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		display_log(philo, "has taken a fork");
	}
}

void	eating(t_philos *philo)
{
	long	curr;

	if (philo->table->num_philos == 1)
		return ;
	curr = get_current_time();
	display_log(philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->last_meal_timing = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->meal_mutex);
	while (check_death(philo->table))
	{
		if ((get_current_time() - curr) >= (long)philo->table->time_to_eat)
			break ;
		usleep(50);
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	check_death(t_table *table)
{
	pthread_mutex_lock(&table->death_mutex);
	if (table->someone_died)
	{
		pthread_mutex_unlock(&table->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(&table->death_mutex);
	return (1);
}

void	sleeping(t_philos *philo)
{
	long	curr;

	curr = get_current_time();
	display_log(philo, "is sleeping");
	while (check_death(philo->table))
	{
		if ((get_current_time() - curr) >= (long)philo->table->time_to_sleep)
			return ;
		usleep(50);
	}
}

void	thinking(t_philos *philo)
{
	display_log(philo, "is thinking");
	usleep(200);
}
