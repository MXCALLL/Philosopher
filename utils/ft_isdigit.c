/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:08:39 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/13 20:10:50 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_whitespace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_isdigit(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_whitespace(str[i]))
		{
			i++;
			continue ;
		}
		if (!(str[i] >= '0' && str[i] <= '9'))
			flag = 1;
		i++;
	}
	if (flag)
		return (1);
	return (0);
}
