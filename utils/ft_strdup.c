/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <muidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:47:54 by muidbell          #+#    #+#             */
/*   Updated: 2025/07/10 17:30:11 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*s_ptr;
	int		len;

	len = ft_strlen(s);
	s_ptr = (char *)malloc(len + 1);
	if (s_ptr == NULL)
		return (NULL);
	while (*s != 0)
		*s_ptr++ = *s++;
	*s_ptr = '\0';
	return (s_ptr - len);
}
