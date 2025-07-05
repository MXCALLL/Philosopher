/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 07:21:52 by muidbell          #+#    #+#             */
/*   Updated: 2025/06/11 10:00:36 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(int nbr, int index)
{
	if (index == 1)
	{
		if (!nbr)
		{
			ft_putstr("Error: Invalid Number of Philosophers");
			return (1);
		}
	}
	else if (index == 2 || index == 3 || index == 4)
	{
		if (!nbr)
		{
			ft_putstr("Error: Invalid Time Number");
			return (1);
		}
	}
	else if (index == 5)
	{
		if (!nbr)
		{
			ft_putstr("Error: Invalid number of meals per philosopher");
			return (1);
		}
	}
	return (0);
}

int	check_posoverflow(int ac, char **av)
{
	int		i;

	i = 0;
	while(i < ac)
	{
		if (ft_atoi(av[i]) == -2)
		{
			write(1, "Error: Numbers Must be Positive\n", 25);
			return (1);
		}
		else if (ft_atoi(av[i]) == -1)
		{
			write(1, "Error: Numbers Must be must between 1 to 2147483647\n", 44);
			return (1);
		}
		else if (ft_error(ft_atoi(av[i]), i))
			return (1);
		i++;
	}
	return (0);
}

int	filter_input(int ac, char **av)
{
	if (ac != 6 && ac != 7)
	{
		ft_putstr("Error: nbr of args is not enough");
		return (1);
	}
	if (check_posoverflow(ac, av))
		return (1);
	return (0);
}
