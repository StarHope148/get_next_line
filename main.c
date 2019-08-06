/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:16:41 by jcanteau          #+#    #+#             */
/*   Updated: 2019/07/16 16:20:51 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		n;

	if (argc == 2)
	{
		fd = open("fichiertxt", O_RDONLY);
		i = 0;
		n = atoi(argv[1]);
		while (i < n)
		{
			i++;
			printf("return_var = [%d]\t--->\t(1 = line read, 0 = EOF, -1 = Error)\n", get_next_line(fd, &line));
			printf("\nLINE = \"%s\"\n---------------------------------\n", line);
		}
		close(fd);
	}
	return (0);
}
