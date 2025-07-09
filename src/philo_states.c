/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:13:12 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/09 19:01:19 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	taking_fork(t_philos *philo)
{
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
	display_log(philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->last_meal_timing = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->meal_mutex);

	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philos *philo)
{
	display_log(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
}

void	thinking(t_philos *philo)
{
	display_log(philo, "is thinking");
}

