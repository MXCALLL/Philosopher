/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 07:02:37 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/11 17:24:49 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philos	*philos;
	t_table		*table;

	table = NULL;
	if (filter_input(ac, av))
		return (1);
	table = init_table(table, ac, av);
	if (!table)
		return (cleanup(table, NULL), 1);
	if (table->num_philos == 1)
	{
		pthread_mutex_lock(&table->print_mutex);
		printf("0 1 has taken a fork\n");
		ft_usleep(table->time_to_die);
		printf("%zu 1 died\n", table->time_to_die);
		pthread_mutex_unlock(&table->print_mutex);
		return (cleanup(table, NULL), 0);
	}
	philos = init_philos(table);
	if (!philos)
		return (1);
	create_threads(philos, table);
	cleanup(table, philos);
	return (0);
}
