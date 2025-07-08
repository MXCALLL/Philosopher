/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:07:13 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/08 12:27:57 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_simulation(void *data)
{
	t_philos *philo;
	philo = (t_philos *)data;

	pthread_mutex_lock(&philo->table->print_mutex);
	printf("id= %zu\n", philo->id);
	pthread_mutex_unlock(&philo->table->print_mutex);
	return (NULL);
}
