NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_utils.c ft_print_u.c ft_print_x.c ft_print_p.c ft_print_s.c ft_print_int.c
FLAGS = -Wall -Werror -Wextra

OBJS = $(SOURCES:.c=.o)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
		cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all