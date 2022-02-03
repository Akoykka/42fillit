

all:
	gcc -o solver -g solve.c get_next_line.c -L ./libft -lft

validator:
	gcc -o validator -g solve.c -L ./libft -lft