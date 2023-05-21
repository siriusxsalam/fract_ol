# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 20:32:53 by hasalam           #+#    #+#              #
#    Updated: 2023/03/20 11:35:23 by hasalam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c\
		ft_putchar.c\
		ft_helper.c\
		printsetup.c

BONUS = ft_printf_bonus.c\
		ft_putchar.c\
		ft_helper.c\
		utils_bonus.c\
		printsetup.c

CC = cc
RM = rm -f
CFALGS = -Wall -Wextra -Werror

OBJS = $(SRCS:%.c=%.o)

OBJSBONUS = $(BONUS:%.c=%.o)

all: ${NAME}

%.o:%.c ft_printf.h
	${CC} ${CFALGS} -c $<

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

bonus: $(OBJSBONUS)
	ar rcs ${NAME} ${OBJSBONUS}

clean:
	${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: fclean clean re all bonus