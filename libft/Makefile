CFILES			=	ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c	\
					ft_strlen.c ft_strrchr.c  ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcmp.c		\
					ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_isalnum.c	\
					ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c	\
					ft_substr.c ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c 		\
					ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_strcat.c ft_strcpy.c		\
					ft_putstr_fd_endl.c
BONUS_CFILES	= 	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstdelone.c
NAME			=	libft.a
CC				= 	cc
O_FILES			=	$(CFILES:.c=.o)
BONUS_O_FILES	= 	$(BONUS_CFILES:.c=.o)
CFLAGS			= 	-Wall -Wextra -Werror
HEADER			= 	libft.h
FT_PRINTF_DIR	=	ft_printf
GNL_DIR			=	gnl
FT_PRINTF_LIB	=	$(FT_PRINTF_DIR)/libftprintf.a
GNL_LIB			=	$(GNL_DIR)/get_next_line.a

all: $(NAME)

$(NAME): $(CFILES) $(O_FILES) $(HEADER) $(FT_PRINTF_LIB) $(GNL_LIB)
	ar -rcs $(NAME) $(O_FILES) $(FT_PRINTF_LIB) $(GNL_LIB)

bonus: $(CFILES) $(BONUS_CFILES) $(O_FILES) $(BONUS_O_FILES) $(HEADER)
	ar -rcs $(NAME) $(O_FILES) $(BONUS_O_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

clean:
	rm -f $(O_FILES)
	rm -f $(BONUS_O_FILES)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re