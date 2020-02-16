source = $(wildcard *.c)
objects = $(source:.c=.o)
flags = -g -Wall -Wextra

all: $(objects)

%.o : %.c
	gcc $(flags) -c -I. $<

clean:
	rm -rf $(objects)

fclean: clean

re: fclean all
