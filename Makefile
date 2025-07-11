NAME = philo
SRCS = src/main.c src/parsing.c src/init_structs.c src/philos_utils.c \
       src/philo_states.c src/monitor_routine.c utils/ft_atoi.c \
	   utils/ft_putstr.c utils/ft_calloc.c
HEADER = includes/philo.h
OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME}

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -r ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all