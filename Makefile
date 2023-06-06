SRCS = sources/tools.c \
	   philosophers.c

NAME = philo
CFLAGS = -Wall -Werror -Wextra 
OBJS = ${SRCS:.c=.o}
BOBJS = ${BSRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	cc ${CFLAGS} ${SRCS} -o ${NAME}

clean :
		rm -f ${OBJS} ${BOBJS}
fclean : clean
		rm -f ${NAME} ${BNAME}

re : fclean all