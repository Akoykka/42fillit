/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:36:34 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/17 22:34:25 by akoykka          ###   ########.fr       */
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
	if (++linecount == 63)
		printf("");
	printf("%s\n", destination); 
}

return (999);
}