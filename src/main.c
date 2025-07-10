/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 07:02:37 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/10 19:41:02 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_philos	*philos;
	t_table		*table;

	table = NULL;
	if (filter_input(ac, av))
		return (1);
	table = init_table(table, ac, av);
	if (!table)
		return (1);
	philos = init_philos_monitor(table);
	if (!philos)
		return (1);

	cleanup(table, philos);
	return (0);
}
