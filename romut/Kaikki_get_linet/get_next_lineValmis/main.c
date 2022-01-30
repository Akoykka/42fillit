/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:36:34 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/23 00:06:29 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
int fd = open("testfile", O_RDONLY);
char *destination;
int status;
size_t linecount;
linecount = 0;
status = 1;

//destination = (char *)malloc(sizeof(char) * 11 + 1);
//strcpy(destination, "tastaalkaa:");
while(status)
{
	status = get_next_line(fd, &destination);
	printf("%s\n", destination); 
	free(destination);
}


close(fd);

fd = open("testfile", O_RDONLY);
int fd2 = open("testfile2", O_RDONLY);
int fd3 = open("testfile3", O_RDONLY);

status = get_next_line(fd, &destination);
printf("%s\n", destination); 
free(destination);
destination = NULL;
status = get_next_line(fd2, &destination);
printf("%s\n", destination);
free(destination);
destination = NULL;
status = get_next_line(fd3, &destination);
printf("%s\n", destination); 
free(destination);
destination = NULL;

return (999);
}