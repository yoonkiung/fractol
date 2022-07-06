# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonkiung <kiyoon@student.42seoul.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 11:46:12 by yoonkiung         #+#    #+#              #
#    Updated: 2022/07/05 11:46:13 by yoonkiung        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol

LIBFT       = libft

LIBFT_LIB   = libft.a

SRCS        = *.c #수정필요

OBJS        = $(SRCS:.c=.o)

INCS        = .

RM          = rm -f

CC          = gcc

CFLAGS      = -Wall -Wextra -Werror

MLX			= -L./mlx -lmlx -framework OpenGL -framework AppKit

arch		= arch -x86_64
.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) .
	$(ARCH) $(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJS) $(LIBFT_LIB)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS) $(LIBFT_LIB)
	make clean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
