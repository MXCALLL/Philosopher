/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:48:11 by muidbell          #+#    #+#             */
/*   Updated: 2025/06/11 07:40:00 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_overflow(long result, int next_digit)
{
	if ((result > INT_MAX / 10) || (result == INT_MAX / 10))
	{
		if (result > INT_MAX / 10 || next_digit > 7)
			return (-1);
		else if (result > INT_MAX / 10 || next_digit > 8)
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			overflow_check;
	int			next_digit;
	long		result;

	sign = 1;
	result = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (-2);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		next_digit = *str - '0';
		overflow_check = check_overflow(result, next_digit);
		if (overflow_check != 1)
			return (overflow_check);
		result = result * 10 + next_digit;
		str++;
	}
	return ((int)(result * sign));
}
