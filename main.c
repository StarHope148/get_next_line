/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:16:41 by jcanteau          #+#    #+#             */
/*   Updated: 2019/09/18 17:13:54 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		n;
	int		val;

	if (argc == 2)
	{
		fd = open("testtxt", O_RDONLY);
		n = atoi(argv[1]);
		while (n--)
		{
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
