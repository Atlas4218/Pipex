# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rastie <rastie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 19:13:04 by rastie            #+#    #+#              #
#    Updated: 2023/06/18 17:14:27 by rastie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex 

SRC = src
INC = inc
BIN = bin
LIB = libft

SOURCE = ${SRC}/main.c\
	 ${SRC}/get_next_line.c\
	 ${SRC}/heredoc.c\
	 ${SRC}/get_next_line_utils.c

OBJECT = ${patsubst %,${BIN}/%, ${notdir ${SOURCE:.c=.o}}}

CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f
CC = cc

${BIN}/%.o : ${SRC}/%.c 
	mkdir -p ${BIN};\
		${CC} ${CFLAGS} -I${INC} -I${LIB} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJECT}
	make -C ${LIB};\
		${CC} -o ${NAME} ${OBJECT} -L${LIB} -lft -I${LIB};

clean:
	${RM} ${OBJECT};\
		make -C ${LIB} clean;

fclean:	clean
	make -C ${LIB} fclean;\
		${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
