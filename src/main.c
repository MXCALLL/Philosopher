/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 07:02:37 by muidbell          #+#    #+#             */
/*   Updated: 2025/06/11 20:46:28 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_philos	*philos;
	t_philos	*waiter;

	if (filter_input(ac, av))
		return (1);

	philos = initialize_structs(ac, av);

	return (0);
}

