/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 07:02:37 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/15 16:37:11 by muidbell         ###   ########.fr       */
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
	philos = init_philos(table);
	if (!philos)
		return (cleanup(table, NULL), 1);
	create_threads(philos, table);
	cleanup(table, philos);
	return (0);
}
