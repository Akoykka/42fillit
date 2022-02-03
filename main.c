#include <stdio.h>
#include "./libft/includes/libft.h"
#include <fcntl.h>
#define fail 1
#define success 0


int	adjacency(char *tetromino, int index)
{
	if (index >= 4)
	{
		if (tetromino[index - 5] == '#')
			return (success);
	}
	if (index >= 1)
	{
		if (tetromino[index - 1] == '#')
			return (success);
	}
	if (tetromino[index + 1] == '#')
		return(success);

	if (index <= 14)
	{
		if (tetromino[index + 5] == '#')
			return (success);
	}
	return (fail);
}

int	checkadjacency(char *tetromino)
{
	int	i;

	i = 0;
	while (tetromino[i])
	{
		if (tetromino[i] == '#' && adjacency(tetromino, i) == fail)
			return (fail);
		++i;
	}
	return (success);
}

int	checktetromino(char *tetromino)
{
	int	blocks;
	int	loops;
	int	i;

	i = 0;
	blocks = 0;
	while (i < 20 && tetromino[i])
	{
		loops = 0;
		while (loops < 4 && tetromino[i])
		{
			if (tetromino[i] == '#')
				++blocks;
			else if (tetromino[i] != '.')
				return (fail);
			++loops;
			++i;
		}
		if (tetromino[i] != '\n')
			return (fail);
		++i;
	}
	if (blocks == 4
		&& checkadjacency(tetromino) == success 
		&& tetromino[20] == '\n')
		return (success);
	return (fail);
}

int	copysingletetromino(int fd, char **tetromino)
{
	char	buf[21 + 1];
	int		r_value;

	ft_memset(buf, 0, 22);
	r_value = read(fd, &buf, 21);
	if (r_value != 0)

		*tetromino = ft_strdup(buf);
	return (r_value);
}

int	validateinput(const char *filename)
{
	int		fd;
	char	*tetromino;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Invalid file", 2);
	while (copysingletetromino(fd, &tetromino) != 0)
	{
		if (checktetromino(tetromino) == fail)
			return (fail);
		ft_strdel(&tetromino);
	}
	close(fd);
	return (success);
}


int main (int argc, const char **argv)
{

	if (argc != 2)
	{
		printf("USAGE\n");
		return (0);
	}
	if (validateinput(argv[1]) == fail)
	{
		printf("INVALID FILE\n");
		return (0);
	}
	printf("VALID FILE ! CONGRATZ !\n");

	return (0);
}
