# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 17:45:39 by smatsuo           #+#    #+#              #
#    Updated: 2023/08/17 01:09:12 by smatsuo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CFLAGS 		= -Wall -Wextra -Werror
DFLAGS 		= -g -fsanitize=address,undefined
LFLAGS		= -L$(LIBDIR)/libft -lft -L$(LIBDIR)/ft_printf -lftprintf
SRCDIR		= ./src
MSRCS		:= $(shell find $(SRCDIR) -type f -name '*.c')
MOBJS		:= $(MSRCS:.c=.o)
LIBDIR		= ./libs
LIBARC		= $(LIBDIR)/libft/libft.a $(LIBDIR)/ft_printf/libftprintf.a
INCLUDEDIR	= ./includes $(LIBDIR)/ft_printf/includes $(LIBDIR)/libft
INCLUDES	= $(addprefix -I ,$(INCLUDEDIR))

ifeq ($(IS_DEBUG), 1)
	CFLAGS += $(DFLAGS)
endif

all: $(NAME)

bonus: all

$(NAME): $(MOBJS) $(LIBARC)
	$(CC) -o $(NAME) $(CFLAGS) $(LFLAGS) $(INCLUDES) $(MOBJS)

.c.o: ./includes/push_swap.h
	$(CC) -c -o $@ $(CFLAGS) $(INCLUDES) $<

$(LIBARC):
	make -C $(LIBDIR)/libft bonus
	make -C $(LIBDIR)/ft_printf bonus

debug:
	make IS_DEBUG=1

norm:
	norminette -R CheckForbiddenSourceHeader

setup:
	$(RM) compile_commands.json
	compiledb make
	compiledb make bonus

re: fclean all

clean:
	rm -f $(MOBJS)
	make -C $(LIBDIR)/libft clean
	make -C $(LIBDIR)/ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR)/libft fclean
	make -C $(LIBDIR)/ft_printf fclean

.PHONY: all clean fclean re
