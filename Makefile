NAME = so_long
SRCS = so_long.c map_parser.c render.c utils.c movement.c path_is_valid.c gnl/get_next_line.c printf/ft_printf.c

CFLAGS = -Wall -Werror -Wextra -I../../minilibx-linux -g
LFLAGS = -L../../minilibx-linux -lmlx -lX11 -lXext

OBJS = $(SRCS:.c=.o)

GNL_LIB = ./gnl/libgnl.a
PRINTF_LIB = ./printf/libftprintf.a

$(NAME): $(OBJS) $(GNL_LIB) $(PRINTF_LIB)
		cc $(OBJS) -o $(NAME) $(LFLAGS) $(GNL_LIB) $(PRINTF_LIB)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
