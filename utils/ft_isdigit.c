/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:08:39 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/18 11:26:50 by muidbell         ###   ########.fr       */
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
	int	digit_found;

	i = 0;
	flag = 0;
	digit_found = 0;
	while (str[i] && ft_whitespace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		digit_found = 1;
		i++;
	}
	while (str[i] && ft_whitespace(str[i]))
		i++;
	if (str[i] || !digit_found)
		flag = 1;
	return (flag);
}
