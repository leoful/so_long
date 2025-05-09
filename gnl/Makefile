SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

NAME = libgnl.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
