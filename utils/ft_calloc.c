/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:32:39 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/07 11:36:07 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_ptr;
	size_t			i;

	s_ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t		totalby;
	void		*ptr;

	totalby = count * size;
	if (count != 0 && totalby / count != size)
		return (NULL);
	ptr = malloc(totalby);
	if (ptr == NULL)
		return (NULL);

	ft_bzero(ptr, totalby);
	return (ptr);
}
