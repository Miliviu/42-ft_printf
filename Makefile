# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhagon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 10:37:25 by juhagon           #+#    #+#              #
#    Updated: 2021/11/22 10:25:29 by juhagon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_putnbr.c ft_point.c 

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

AR = ar -rcs


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
		${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean: 	clean
		${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re 
