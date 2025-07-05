/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 06:57:56 by muidbell          #+#    #+#             */
/*   Updated: 2025/06/14 19:17:59 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct s_table
{
	size_t				num_philos;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				meals_per_philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	int					someone_died;
	long				start_time_ms;
	struct s_philos		*philos;
}	t_table;

typedef struct s_philos
{
	size_t				id;
	long				last_meal;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_table				*table;
}	t_philos;


// libft functions
int		ft_atoi(const char *str);
void	ft_putstr(char *s);
char	*ft_strdup(const char *s);

// parsing functions
int	filter_input(int ac, char **av);

// src functions
t_philos *initialize_structs(int ac, char **av);
