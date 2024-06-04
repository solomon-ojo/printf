# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sojo <sojo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 14:28:04 by sojo              #+#    #+#              #
#    Updated: 2024/04/29 19:33:30 by sojo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftprintf.a
CC =			cc
CFLAGS =		-Wall -Wextra -Werror
SRCS =			ft_printf_utils.c ft_printf.c
OBJS =			${SRCS:.c=.o}
LIBFT_SRCS =	$(wildcard libft/*.c)
LIBFT_OBJS =	$(LIBFT_SRCS:.c=.o)

all:	$(NAME)
$(NAME):	$(OBJS) libft/libft.a
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

$(OBJS):	%.o: %.c libft/libft.h
	$(CC) $(CFLAGS) -c -o $@ $<

libft/libft.a: $(LIBFT_SRCS) libft/libft.h
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean:	clean
	make -C libft fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
