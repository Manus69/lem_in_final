#Compiler Options
C_FLAGS =
#Filenames
LIBFT_DIR := libft/
LIBX_DIR := minilibx/
NAME := visu-hex
SRCS := change_value.c\
                charge_to_draw.c\
                control_key.c\
                create_links.c\
                hash_function.c\
                hash_utils.c\
                lines_and_dots.c\
                main.c\
                main_validation.c\
                make_axis.c\
                make_free.c\
                pars_hex.c\
                pars_utils.c\
                rotation.c\
                skitlz_to_map.c\
                structure_init.c\
                structure_init_2.c\
                utils_for_axis.c\
                validate_rooms.c\
                zero_to_structures.c convert_lemin_fdf.c find_visual_nodes.c base_draw.c leminization.c\
				base_draw_01.c main_helper.c structure_init_1.c structure_init_3.c validate_rooms_01.c
OBJECTS := $(SRCS:.c=.o)
HEADER = libft/libft.h
all: $(NAME)
$(NAME): $(OBJECTS)
	@make -C $(LIBFT_DIR)	
	@gcc -o $(NAME) $(OBJECTS) -L$(LIBFT_DIR) -lft -L. -lmlx -framework OpenGL -framework AppKit
$(OBJECTS): %.o: %.c
	@gcc $(C_FLAGS) -o $@ -c $<

clean:
	@make clean -C $(LIBFT_DIR)
	@/bin/rm -f $(OBJECTS)
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a
re: fclean all

