/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:39:31 by jcanteau          #+#    #+#             */
/*   Updated: 2019/08/08 17:31:11 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check_newline(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static int	ft_readline(char **str, int fd, char **line)
{
	char		buff[BUFF_SIZE];
	int			ret;
	char		*str_tmp;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!*str)
			if ((*str = malloc(sizeof(char) * ret)) == NULL)
				return (-1);
		str_tmp = ft_strjoin(*str, buff);
		free(*str);
		*str = str_tmp;
	}
	if (ret == -1)
		return (-1);
	if (ft_strlen(*str) == 0)
		return (0);
	*line = ft_strsub(*str, 0, ft_check_newline(*str));
	str_tmp = ft_strsub(*str, ft_check_newline(*str) + 1,
	ft_strlen(*str) - ft_check_newline(*str) - 1);
	free(*str);
	*str = str_tmp;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str = NULL;

	if (fd == -1 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	return (ft_readline(&str, fd, line));
}
