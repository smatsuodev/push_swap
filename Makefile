NAME		= push_swap
CFLAGS 		= -Wall -Wextra -Werror $(LFLAGS)
DFLAGS 		= $(CFLAGS) -g -fsanitize=address,undefined
LFLAGS		= -L$(LIBDIR)/libft -lft -L$(LIBDIR)/ft_printf -lftprintf
SRCDIR		= ./src
MSRC		:= $(shell find $(SRCDIR) -type f -name '*.c')
LIBDIR		= ./libs
LIBARC		= $(LIBDIR)/libft/libft.a $(LIBDIR)/ft_printf/libftprintf.a
INCLUDEDIR	= ./includes $(LIBDIR)/ft_printf/includes $(LIBDIR)/libft
INCLUDES	= $(addprefix -I ,$(INCLUDEDIR))

all: $(NAME)

bonus: all

ifdef IS_DEBUG
$(NAME): $(LIBARC) $(MSRC)
	$(CC) -o $(NAME) $(DFLAGS) $(INCLUDES) $(MSRC)
else
$(NAME): $(LIBARC) $(MSRC)
	$(CC) -o $(NAME) $(CFLAGS) $(INCLUDES) $(MSRC)
endif

ifdef IS_DEBUG
$(LIBARC):
	make debug -C $(LIBDIR)/libft
	make debug -C $(LIBDIR)/ft_printf
else
$(LIBARC):
	make -C $(LIBDIR)/libft
	make -C $(LIBDIR)/ft_printf
endif

debug: fclean
	make IS_DEBUG=1
	make clean

norm:
	norminette -R CheckForbiddenSourceHeader

setup:
	$(RM) compile_commands.json
	compiledb make
	compiledb make bonus

re: fclean all

clean:
	rm -f *.o *.a
	make -C $(LIBDIR)/libft clean
	make -C $(LIBDIR)/ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR)/libft fclean
	make -C $(LIBDIR)/ft_printf fclean

.PHONY: all clean fclean re
