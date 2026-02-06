# files live here
ROOT			:= source

INIT			:=	$(ROOT)/init

TEXTURES_INIT	:=	$(ROOT)/textures_init

RUNTIME			:=	$(ROOT)/runtime

SRC_ROOT		:= $(ROOT)/cub3d.c

SRC_INIT		:=	$(INIT)/err.c							\
					$(INIT)/ft_free_data.c					\
					$(INIT)/utils_1.c						\
					$(INIT)/ft_read_from_file.c				\
					$(INIT)/map_check_utils_1.c				\
					$(INIT)/ft_init.c						\
					$(INIT)/ft_init_2.c						\
					$(INIT)/textures_check.c				\
					$(INIT)/map_check.c						\
					$(INIT)/ft_read_from_file_2.c

SRC_TEXTURES	:=	$(TEXTURES_INIT)/ft_load_images.c		\
					$(TEXTURES_INIT)/ft_make_minimap.c		\
					$(TEXTURES_INIT)/ft_mlx_window_init.c

SRC_RUNTIME		:=	$(RUNTIME)/custom_mlx_pixel_put.c		\
					$(RUNTIME)/ft_keyhooks.c				\
					$(RUNTIME)/ft_terminate.c				\
					$(RUNTIME)/ft_direction.c				\
					$(RUNTIME)/ft_fps_counter.c				\
					$(RUNTIME)/ft_minimap.c					\
					$(RUNTIME)/ft_minimap_2.c				\
					$(RUNTIME)/ft_position.c				\
					$(RUNTIME)/utils.c						\
					$(RUNTIME)/ft_raycasting_1.c			\
					$(RUNTIME)/ft_raycasting_2.c

CFILES			:=	$(SRC_INIT)								\
					$(SRC_ROOT)								\
					$(SRC_TEXTURES)							\
					$(SRC_RUNTIME)
