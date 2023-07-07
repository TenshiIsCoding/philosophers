# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaher <azaher@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 06:39:52 by azaher            #+#    #+#              #
#    Updated: 2023/06/18 06:39:52 by azaher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = sources/tools.c \
	   sources/ft_atoitoa.c \
	   sources/initialisation.c \
	   sources/init_tools.c \
	   sources/philo_tools.c \
	   philosophers.c

NAME = philo
CFLAGS = -Wall -Wextra
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