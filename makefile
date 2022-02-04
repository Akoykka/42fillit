

all:
	gcc -o solver -g solve.c malloc_check.c -L ./libft -lft

validator:
	gcc -o validator -g solve.c -L ./libft -lft