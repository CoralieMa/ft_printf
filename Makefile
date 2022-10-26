# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 13:51:06 by cmartino          #+#    #+#              #
#    Updated: 2022/10/26 16:41:30 by cmartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
			ft_type.c \
			ft_print_ptr.c \
			ft_convert_base_hexa.c \
			ft_put_un_nbr_fd.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

LIB_PATH = libft/

DEP = libft.a

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all :	${NAME}

${NAME}:	${DEP} ${OBJS}
		ar rcs ${NAME} ${OBJS}

${DEP}:		
		@make -C ${LIB_PATH}
		mv libft/${DEP} ${NAME}

clean:
	@make fclean -C ${LIB_PATH}
	${RM} ${OBJS}

fclean:	clean
	${RM} ${LIB_PATH}${DEP}
	${RM} ${NAME}

re:	fclean all

test: ${NAME}
	@${CC} ${CFLAGS} main.c libftprintf.a
	@echo "\n---------------------------------\n"
	@./a.out
	@echo "\n---------------------------------\n"
	@${RM} a.out 

.PHONY:	all clean fclean re test
