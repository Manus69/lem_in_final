files = $(wildcard *.c)
file_objects = $(files:.c=.o)
release_flags = -Wall -Wextra -Werror
NAME = libftprintf.a
header = four_header.h
lib_header = libft.h

all: $(NAME)

$(NAME): $(file_objects)
	ar rcs $(NAME) $(file_objects)

%.o : %.c $(header) $(lib_header)
	gcc $(release_flags) -c $< -I.

run: $(wildcard *.c)
	gcc -Wall -Wextra -o run $^ -I.

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:
	make clean
	make all

debug: $(wildcard *.c)
	gcc -g -Wall -Wextra -o run $^ -I.
