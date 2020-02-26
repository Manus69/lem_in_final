NAME := lem-in
headers = $(wildcard ./headers/*.h)
objects = $(source:.c=.o)

SRCS_DIR := will_it_work
SRCS_FILES := main_validation.c create_links.c create_links_01.c pars_hex.c pars_utils.c structure_init.c structure_init_2.c\
			hash_function.c hash_utils.c make_free.c validate_rooms.c structure_init_1.c structure_init_3.c\
			validate_rooms_01.c ants.c copy_stuff.c count_paths.c destroy.c display_stuff.c distribute_ants.c\
			flow.c generic_list.c get_stuff.c jam.c node_stack.c node.c path_list.c path.c\
			pathfinder.c plug.c reset.c saturate.c stack.c superimpose_backwards.c superimpose_forwards.c superimpose.c\
			support.c undo_flow.c waste_of_time.c run.c run_extra_functions.c
source := $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

LIBF_DIR := library_routines
LIBF_FILES := ft_itoa.c ft_memcpy.c ft_memmove.c ft_strsplit.c why_int_absolute_value.c why_int_power.c
lib_functions = $(addprefix $(LIBF_DIR)/, $(LIBF_FILES))
lib_objects = $(lib_functions:.c=.o)

source_directory = ./will_it_work/

test_flags = -Wall -Wextra -Werror

VISUAL := visu-hex

LIB_PRINT := printf/libftprintf.a

all: $(NAME) $(VISUAL)

$(NAME): $(LIB_PRINT) $(objects) $(lib_objects)
	gcc $(test_flags) $^ -I ./headers -L./printf -lftprintf -o $(NAME)


%.o : %.c $(headers)
	gcc $(test_flags) -c $< -I./headers -o $@

$(source_directory)%.o: %.c $(headers)
	gcc $(test_flags) -c $< -o $@

.FORCE:

$(VISUAL): 
	make -C ./visualization
	cp ./visualization/visu-hex .

del_visual:
	rm visu-hex
	make fclean  -C ./visualization

$(LIB_PRINT):.FORCE
	make -C ./printf
	make -C ./library_routines

clean:
	rm -f ./will_it_work/*.o
	make clean -C ./visualization

fclean: clean del_visual
	make fclean -C ./printf
	make fclean -C ./library_routines
	rm -f $(NAME)
	rm -f $(VISUAL)

re: fclean all
