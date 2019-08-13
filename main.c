/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:16:41 by jcanteau          #+#    #+#             */
/*   Updated: 2019/08/13 16:39:11 by jcanteau         ###   ########.fr       */
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
	int		val;

	if (argc == 2)
	{
		fd = open("testtxt", O_RDONLY);
		i = 0;
		n = atoi(argv[1]);
		while (i < n)
		{
			i++;
			val = get_next_line(fd, &line);
			printf("return_var = [%d]\t--->\t(1 = line read, 0 = EOF, -1 = Error)\n", val);
			printf("\nLINE = \"%s\"\n---------------------------------\n", line);
			if (line)
			{
				free(line);
				line = NULL;
			}
		}
		close(fd);
	}
	return (0);
}
