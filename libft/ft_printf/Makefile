CFILES	=	ft_converse.c ft_print.c ft_printf.c
CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror
NAME	=	libftprintf.a
OFILES	=	$(CFILES:.c=.o)
HEADER	=	ft_printf.h

all: $(NAME)

$(NAME): $(HEADER) $(CFILES) $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus clean fclean re all
