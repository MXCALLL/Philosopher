/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:47:54 by muidbell          #+#    #+#             */
/*   Updated: 2025/06/11 20:48:07 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
