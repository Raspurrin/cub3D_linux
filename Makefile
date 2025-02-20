CC			:= gcc
DEBUG ?= 0
AU_FLAG = -DBONUS

ifeq ($(DEBUG), 1)
    CFLAGS         =    -g -ggdb -Wall -Wextra -Werror
else
    CFLAGS        =   -O3 -Wall -Wextra -Werror -g -fsanitize=address
endif

# SRC subdirrectories #
VALIDATOR_FILES := validate_cub_file.c validate_map.c matrix_neighbour_check.c map_checks.c \
					validate_texture_names.c get_door.c validate_texture_names_2.c
VALIDATOR := $(addprefix validation/,$(VALIDATOR_FILES))

CONSTRUCTOR_FILES := constructor.c open_cub_file.c initiate_video.c destructor.c \
					open_textures_xmp.c set_utils.c set_sprites.c \
					set_sprites_2.c open_sprite_ini.c destructor_2.c $(VALIDATOR) 
CONSTRUCTOR := $(addprefix constructor/,$(CONSTRUCTOR_FILES))
DISPLAY_FILES := display.c minimap.c minimap_2.c raycast.c draw_vertical_line.c intersection_distances.c \
				draw_floor_and_ceiling.c sprite_draw.c menu.c sprite_draw_calculate.c \
				sprite_draw_single.c set_sprite_frame.c bigmap.c
DISPLAY := $(addprefix display/,$(DISPLAY_FILES))
MECHANICS_FILES := player_movement.c move_player.c movement_vector.c trigger_area.c
MECHANICS := $(addprefix mechanics/,$(MECHANICS_FILES))
ENGINE_FILES := engine.c $(DISPLAY) $(MECHANICS)
ENGINE := $(addprefix engine/,$(ENGINE_FILES))
CONTROL_FILES := key_hooks.c rotate_player.c more.c
CONTROL := $(addprefix control/,$(CONTROL_FILES))
UTIL_FILES := file_to_heap.c find_char.c ft_color.c len_func.c \
				list_to_array.c match_str.c pixel_matrix.c delete_list.c \
				math_functions.c game_mech.c fill_screen_color.c \
				xpm_to_texture.c time.c math_functions2.c delocate.c ft_color_2.c
UTIL := $(addprefix utils/,$(UTIL_FILES))
# SRC subdirrectories #

SRC_FILES	:= cube3d.c audio.c $(CONSTRUCTOR) $(ENGINE) $(CONTROL) $(UTIL)
SRCDIR		:= src/
SRC			:= $(addprefix $(SRCDIR),$(SRC_FILES))
NAME		:= cub3d
LIBFT		:= $(SRCDIR)libs/libft/libft.a

ifeq ($(shell uname -s),Darwin)
	LBMLX	:= $(SRCDIR)libs/mlx/libmlx.a
	LIBS	:= -Lsrc/libs/mlx -framework OpenGL -framework AppKit
else
	LBMLX	:= $(SRCDIR)libs/mlx/libmlx_Linux.a
	LIBS	:= -lXext -lX11 -lm
endif

all: $(NAME)

re: clean $(NAME)

$(NAME): $(LIBFT) $(LBMLX) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LBMLX) $(LIBS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(SRC)
	$(CC) $(CFLAGS) $(AU_FLAG) $(SRC) $(LBMLX) $(LIBS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make bonus -C $(SRCDIR)libs/libft/

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(NAME)

fclean: clean cleanlibs

cleanlibs:
	make fclean -C $(SRCDIR)libs/libft/
