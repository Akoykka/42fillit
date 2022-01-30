
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFF_SIZE 32
#include <stdio.h>
#include <string.h>

static char	*ft_strtoken_w_o_delim(char *str, int delim)
{
	size_t	i;
	char	*token;

	i = 0;
	while (str[i] && str[i] != delim)
		++i;
	token = ft_strndup(str, i - 1);
	if (!token)
		return (NULL);
	return (token);
}

int main(void)
{
	int r_value;
	int fd;
	char buf[BUFF_SIZE + 1];
	fd = open("readtest", O_RDONLY);

	r_value = read(fd, buf, BUFF_SIZE);

	printf("rvalue is %d\n", r_value);

	r_value = read(fd, buf, BUFF_SIZE);

	printf("rvalue is %d\n", r_value);


	r_value = read(fd, buf, BUFF_SIZE);

	printf("rvalue is %d\n", r_value);
	close(fd);

	return (0);



}