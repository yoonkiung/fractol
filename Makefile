# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 14:18:27 by kiyoon            #+#    #+#              #
#    Updated: 2022/07/07 14:18:28 by kiyoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol

LIBFT       = libft

LIBFT_LIB   = libft.a

SRCS        = ./main.c ./keypress.c ./shape.c

OBJS        = $(SRCS:.c=.o)

INCS        = .

RM          = rm -f

CC          = gcc

CFLAGS      = -Wall -Wextra -Werror

MLX			= -L./mlx -lmlx -framework OpenGL -framework AppKit

MLXClUSTER	= -lmlx -framework OpenGL -framework AppKit

ARCH		= arch -x86_64

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) .
	$(CC) $(CFLAGS) $(MLXClUSTER) -o $(NAME) $(OBJS) $(LIBFT_LIB)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS) $(LIBFT_LIB)
	make clean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
