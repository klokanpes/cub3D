NAME			=	cub3d

CC				=	cc

MLX_FLAGS		=	-L/usr/lib -lXext -lX11 -lm -lz

HEADER			=	includes/cub3d.h
SRC_DIR			=	source
OBJ_DIR			=	build
MINI_REPO		=	https://github.com/42paris/minilibx-linux.git
MINI_DIR		=	minilibx-linux
MINI_LIB		=	$(MINI_DIR)/libmlx.a
LIBFT_DIR		=	libft
LIBFT_TARGET	=	$(LIBFT_DIR)/libft.a
FT_PRINTF_DIR	=	$(LIBFT_DIR)/ft_printf
FT_PRINTF_TARGET=	$(FT_PRINTF_DIR)/libftprintf.a
GET_NEXT_DIR	=	$(LIBFT_DIR)/gnl
GET_NEXT_TARGET	=	$(GET_NEXT_DIR)/get_next_line.a

CFLAGS			=	-Wall -Wextra -Werror -I$(MINI_DIR) $(includes)


include source.mk

OFILES		=	$(CFILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT_TARGET) $(GET_NEXT_TARGET) $(FT_PRINTF_TARGET) $(OFILES) $(MINI_LIB) $(HEADER)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT_TARGET) $(GET_NEXT_TARGET) $(FT_PRINTF_TARGET) \
	$(MINI_LIB) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(MINI_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -O3 -c $< -o $@

$(LIBFT_TARGET):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(FT_PRINTF_TARGET):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GET_NEXT_TARGET):
	$(MAKE) -C $(GET_NEXT_DIR)

$(MINI_DIR):
	@if [ ! -d "$@" ]; then \
		git clone $(MINI_REPO) "$@"; \
	fi

$(MINI_LIB): $(MINI_DIR)
	$(MAKE) -C $(MINI_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GET_NEXT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(MINI_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(GET_NEXT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
