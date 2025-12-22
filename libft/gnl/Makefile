CFILES = get_next_line.c get_next_line_utils.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a
LIB = get_next_line.h
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(CFILES) $(OFILES) $(LIB)
	ar rcs $(NAME) $(OFILES) 

%.o: %.c $(LIB)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all