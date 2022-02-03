/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:25:05 by akoykka           #+#    #+#             */
/*   Updated: 2022/02/03 09:37:17 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/includes/libft.h"
#include <fcntl.h>
#define FAIL 1
#define SUCCESS 0
#define NOT_FOUND 404
#define FOUND 1
int	get_next_line(const int fd, char **line);



typedef struct s_tetromino
{
	int				optimal_solution;
	char			*square;
	char			**tetrominos;
	int 			sidelen;
	int				t_amount;
	char			*answer;
	int				emptyspaces;

} 				t_tetromino;

void copy_except(char *dest, char *src, int c)
{
	int i;

	while (*src)
	{
		if (*src != c)
		{
			*dest = *src;
			dest++;
		}
	src++;
	}
	return;
}

void save_tetrominos(int fd, char **tetrominos)
{
	ssize_t		r_value;
	char 	buf[21 + 1];
	int i;

	ft_memset(buf, '\0', 22);
	r_value = read(fd, &buf, 21);
	while (r_value)
	{
		i = 0;
		*tetrominos = (char *)ft_memalloc(16 + 1);
		copy_except(*tetrominos, buf, '\n');

	tetrominos++;
	r_value = read(fd, &buf, 21);
	}
	return;
}



char *makegrid(int sidelen)
{
	char *square;

	square = (char *)ft_memalloc(sidelen * sidelen + sidelen + 1);
	if (!square)
		exit(1);
	ft_memset(square, '.', sidelen * sidelen);

	return(square);
}

void undo_last_tetromino(char *square, int c)
{
	while(*square)
	{
		if (*square == c)
			*square = '.';
		++square;
	}
}

int emptyspaces(char *square)
{
	int amount;

	amount = 0;
	while(*square)
	{
		if (*square == '.')
			++amount;
	++square;
	}
	return (amount);
}

int wallcollision(char *square, int sidelen, int c)
{
	int	wall_index;

	wall_index = sidelen;
	while(square[wall_index])
	{
		if (square[wall_index] == c && square[wall_index - 1] == c)
		{
			undo_last_tetromino(square,c);
			return (FAIL);
		}
		wall_index = wall_index + sidelen;
	}
	return (SUCCESS);
}



/*
	int wallcollision(char *square, int sidelen, int c)
	int loop;
	int x;

	x = 1;
	loop = sidelen;
	while(loop--)
	{
		if (square[sidelen * x] == square[(sidelen - 1) * x]
		&& square[sidelen * x] != '.')
		{
			undo_last_tetromino(square,c);
			return (FAIL);
		}
		++x;
	}

return (SUCCESS);
}
*/


int convert_to_square_size(int distance, int sidelen)
{
	int converted_len;

	if (distance > 1)
	{
		converted_len = distance + (sidelen - 4);
		return(converted_len);
	}
	return (distance);
}

int get_distance_from_tetromino(char *block, int sidelen)
{
	int	distance;

	distance = 1;
	while (block[distance] != '#')
		++distance;
	return(distance);
}

int collision(char *square, int index, int sidelen, int c, char *tetromino)
{
	char *block;
	int loop;
	int dist_to_next;

	square[index] = c;
	block = ft_strchr(tetromino, '#');

	loop = 3;
	while (loop--)
	{
		dist_to_next = get_distance_from_tetromino(block, sidelen);
		index = index + convert_to_square_size(dist_to_next, sidelen);
		block = block + dist_to_next;
		if (square[index] == '.')
			square[index] = c;
		else
		{
			undo_last_tetromino(square, c);
			return (FAIL);
		}

	}
	return (SUCCESS);
}

int get_first_block_on_row(char *square, int sidelen, int row)
{
	int i;

	if (row == 1)
		i = 0;
	else
		i = 1;

	while (square[i * row] == '.')
	{
		++i;
		if (sidelen - 1 != i)
			return (0);
	}
	return (i);
}
int get_last_block_on_row(char *square, int sidelen, int row)
{
	int i;
	int len_to_last_block;

	i = sidelen;

	while (square[i * row] == '.' &&  i > -1)
		--i;

	return i;
}

int get_highest_horizontal_len(int sidelen, char *square)
{
	int row;
	int highest_value;
	int width_of_tetrominos;
	int first;
	int last;

	highest_value = 0;
	i = 0;
	row = 1;

	while(row <= sidelen)
	{
		first = get_first_block_position_on_row(square, sidelen, row);
		last = get_last_block_position_on_row(square, sidelen, row);

		last - first = width_of_tetrominos;
		if (width_of_tetrominos > highest_value)
			highest_value = width_of_tetrominos;

		++row;
	}
	return (highest_value);
}

int	get_highest_vertical_len(int sidelen, char *square)
{




}

int get_highest_width
{

	get_highest_vertical_len

	get_highest_horizontal_len

	return(highest)
}


void recursive_solver(char **tetrominos, int c, t_tetromino *values)
{
	int i;

	i = 0;
	if (!*tetrominos)
	{
		if (emptyspaces(values->square) < values->emptyspaces)
		{
		 values->answer = ft_strdup(values->square);
		 values->emptyspaces = emptyspaces(values->square);
		}
	}
	else while (values->square[i])
	{
		if (values->square[i] == '.' && values->square[i]
		&&	collision(values->square, i, values->sidelen, c, *tetrominos) == SUCCESS
		&& wallcollision(values->square, values->sidelen, c) == SUCCESS)
		{
			recursive_solver(++tetrominos, ++c, values);
			--c;
			--tetrominos;
			undo_last_tetromino(values->square, c);
		}
		++i;
	}
}

int main (int argc, const char **argv)
{
	int fd;
	t_tetromino *values;
	char 	*square;


	if (argc != 2)
	{
		printf("USAGE\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);

	// validator


	//if (validateinput(argv[1]) == FAIL)
	//{
	//	printf("INVALID FILE\n");
	//	return (0);
	//}

	// Validator end

	values = (t_tetromino *)malloc(sizeof(t_tetromino));
	values->tetrominos = (char **)ft_memalloc(sizeof(char *) * ( 26 + 1));


	save_tetrominos(fd, values->tetrominos);
	values->sidelen = 2;
	values->emptyspaces = 666;
	values->answer = NULL;

	//solver

	while (values->answer == NULL)
	{
		values->square = makegrid(values->sidelen); // redundant unless to check malloc
		recursive_solver(values->tetrominos, 'A', values);
		values->sidelen++;
	}
	//(char **tetrominos, char *square, int c, int sidelen, t_tetromino *values)
	//void recursive_solver(char **tetrominos, int c, t_tetromino *values)
	//solver end


	printf("%s\n", values->answer);
	printf("sidelen for answer is %d\n", values->sidelen);
	printf("strlen is %lu\n", (ft_strlen(values->answer) - 1));
	return (0);
}
