# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 17:45:39 by smatsuo           #+#    #+#              #
#    Updated: 2023/08/18 23:57:07 by smatsuo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CFLAGS 		=	-Wall -Wextra -Werror
DFLAGS 		=	-g -fsanitize=address,undefined
LFLAGS		=	-L$(LIBDIR)/libft -lft -L$(LIBDIR)/ft_printf -lftprintf
SRCDIR		=	./src
MSRCS		:=	./src/array/int_arr.c ./src/array/str_arr.c ./src/error/error.c ./src/main.c ./src/op_list/op_list.c \
				./src/op_list/opt/opt.c ./src/solver/insertion_sort.c ./src/solver/quick_sort/quick_sort.c ./src/solver/sort.c \
				./src/solver/sort_2.c ./src/solver/sort_3.c ./src/solver/sort_4.c ./src/solver/sort_5.c ./src/solver/utils/is_sorted.c \
				./src/stack/constructor.c ./src/stack/controls/basic_controls/at.c ./src/stack/controls/basic_controls/pop.c \
				./src/stack/controls/basic_controls/push.c ./src/stack/controls/basic_controls/record.c ./src/stack/controls/basic_controls/rotate.c \
				./src/stack/controls/print_stack.c ./src/stack/controls/push.c ./src/stack/controls/repeat.c ./src/stack/controls/rev_rotate.c \
				./src/stack/controls/rotate.c ./src/stack/controls/swap.c ./src/stack/destructor.c ./src/stack/node/constructor.c ./src/stack/node/controls/has.c \
				./src/stack/node/controls/insert.c ./src/stack/node/controls/pop.c ./src/stack/node/destructor.c ./src/utils/compress_array.c \
				./src/utils/ft_atoi_arr.c ./src/utils/ft_atoi_ex.c ./src/utils/get_median_in_list.c ./src/utils/min_value_in_list.c ./src/utils/sort.c ./src/validation/validation.c
MOBJS		:=	$(MSRCS:.c=.o)
LIBDIR		=	./libs
LIBARC		=	$(LIBDIR)/libft/libft.a $(LIBDIR)/ft_printf/libftprintf.a
INCLUDEDIR	=	./includes $(LIBDIR)/ft_printf/includes $(LIBDIR)/libft
INCLUDES	=	$(addprefix -I ,$(INCLUDEDIR))

BONUS_NAME	=	checker

ifeq ($(IS_DEBUG), 1)
	CFLAGS += $(DFLAGS)
endif

all: $(NAME)

$(NAME): $(MOBJS) $(LIBARC)
	$(CC) -o $(NAME) $(CFLAGS) $(LFLAGS) $(INCLUDES) $(MOBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): all

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
