/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:39:31 by jcanteau          #+#    #+#             */
/*   Updated: 2019/07/08 16:35:59 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check_init(int fd, char **line, char **str)
{
	if (fd == -1 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (*str == NULL)
		if ((*str = malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)	
			return (-1);
	return (0);
}

static int	ft_check_newline(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (ft_strlen(str));
}

static int	ft_readline(char **str, int fd, char ***line)
{
	char		buff[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		*str = ft_strjoin(*str, buff);
	}
	if (ret == -1)
		return (-1);
	**line = ft_strsub(*str, 0, ft_check_newline(*str));
	if (ft_strlen(*str) == 0)
		return (0);
	*str += ft_strlen(**line) + 1;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	int		return_var;

	return_var = 0;
	if ((return_var = ft_check_init(fd, line, &str)) == -1)
		return (-1);
	if ((return_var = ft_readline(&str, fd, &line)) == -1)
		return (-1);
	return (return_var);
}