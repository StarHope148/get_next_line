/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:58:26 by jcanteau          #+#    #+#             */
/*   Updated: 2019/08/28 19:27:29 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_init_struct(t_read *p, int fd)
{
	if ((p->next = malloc(sizeof(t_read))) == NULL)
		return (NULL);
	p->next->fd = fd;
	p->next->str = NULL;
	p->next->nl = -1;
	p->next->state = 1;
	p->next->next = NULL;
	return (p);
}

static int	ft_check_newline(char *str)
{
	int				i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_fill_line(t_read *d, char **line)
{
	char			*str_tmp;

	if (d->nl == -1)
	{
		if (d->str[0] == '\0')
		{
			free(d->str);
			d->str = NULL;
			d->fd = -1;
			d->nl = -1;
			d->state = 1;
			return (0);
		}
		*line = ft_strsub(d->str, 0, ft_strlen(d->str));
		free(d->str);
		d->str = NULL;
		return (1);
	}
	*line = ft_strsub(d->str, 0, d->nl);
	str_tmp = ft_strsub(d->str, d->nl + 1, ft_strlen(d->str) - d->nl - 1);
	free(d->str);
	d->str = str_tmp;
	return (1);
}

static int	ft_retrieve_line(t_read *d, char **line)
{
	char			buff[BUFF_SIZE + 1];
	char			*str_tmp;
	int				ret;

	while ((d->nl = ft_check_newline(d->str)) == -1 && d->state)
	{
		if ((ret = read(d->fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (ret < BUFF_SIZE)
			d->state = 0;
		buff[ret] = '\0';
		if (!d->str)
		{
			if ((d->str = ft_strdup(buff)) == NULL)
				return (-1);
		}
		else
		{
			str_tmp = ft_strjoin(d->str, buff);
			free(d->str);
			d->str = str_tmp;
		}
	}
	return (ft_fill_line(d, line));
}

int			get_next_line(const int fd, char **line)
{
	static t_read	data = {-1, NULL, -1, 1, NULL};
	t_read			*p;

	p = &data;
	if (fd < 0 || line == NULL)
		return (-1);
	while (p->fd != fd)
	{
		if (p->fd == -1)
			p->fd = fd;
		else if (!p->next)
		{
			if ((ft_init_struct(p, fd)) == NULL)
				return (-1);
			p = p->next;
		}
		else
			p = p->next;
	}
	if (p->state == 0 && !p->str)
		return (0);
	return (ft_retrieve_line(p, line));
}
