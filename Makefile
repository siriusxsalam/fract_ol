# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 18:29:42 by hasalam           #+#    #+#              #
#    Updated: 2023/05/20 03:55:38 by hasalam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

NAME_BONUS = fractol_bonus

SRCS = fractol.c\
		ft_helper.c\
		mandelbrot.c\
		ft_events.c\
		juliaa.c

SRCS_BONUS = burning_bonus.c\
			fractol_bonus.c\
			ft_events_bonus.c\
			ft_helper.c\
			juliaa_bonus.c\
			mandelbrot_bonus.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Imlx -g
MLX = -Imlx -lmlx -framework OpenGL -framework AppKit -o

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

all: ft_printf/libftprintf.a $(NAME)

ft_printf/libftprintf.a:
		make -C ft_printf

%.o:%.c fractol.h
		${CC} ${CFLAGS} -c $<

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) ft_printf/libftprintf.a $(MLX) $(NAME)

bonus : ft_printf/libftprintf.a $(NAME_BONUS)

%.o:%.c fractol_bonus.h
		${CC} ${CFLAGS} -c $<

$(NAME_BONUS): $(OBJS_BONUS)
		$(CC) $(CFLAGS) $(OBJS_BONUS) ft_printf/libftprintf.a $(MLX) $(NAME_BONUS)

clean:
		${RM} ${OBJS} ${OBJS_BONUS}
		make fclean -C ft_printf

fclean: clean
		${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: fclean clean re all