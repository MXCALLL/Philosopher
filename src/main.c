/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 07:02:37 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/09 15:36:51 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_philos	*philos;
	t_table		*table;
	// t_philos	*monitor;

	table = NULL;
	if (filter_input(ac, av))
		return (1);
	table = init_table(table, ac, av);
	if (!table)
		return (1);
	philos = init_philos(table);
	if (!philos)
		return (1);

	return (0);
}
