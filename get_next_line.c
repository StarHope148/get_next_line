/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:58:26 by jcanteau          #+#    #+#             */
/*   Updated: 2019/08/12 00:03:12 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int  ft_check_newline(char *str)
{
    int             i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

static int  ft_readline(t_read *data, char **line)
{
    char            buff[BUFF_SIZE];
    int             ret;
    char            *str_tmp;

    str_tmp = NULL;
    ret = -1;
    if (data->str)
        data->nl = ft_check_newline(data->str);
    while (data->nl == -1 && ret != 0)
    {
        ret = read(data->fd, buff, BUFF_SIZE);
        if (ret == 0 && !data->str)
            return (0);
        if (ret == -1)
            return (-1);
        buff[ret] = '\0';
        if (!data->str)
            if ((data->str = malloc(sizeof(char) * (ret + 1))) == NULL)
                return (-1);
        str_tmp = ft_strjoin(data->str, buff);
        free(data->str);
        data->str = str_tmp;
        data->nl = ft_check_newline(data->str);
    }
    data->nl = ft_check_newline(data->str);
    if (data->nl == -1)
    {
            *line = ft_strsub(data->str, 0, ft_strlen(data->str));
            free (data->str);
            data->str = NULL;
            return (1);
    }
    *line = ft_strsub(data->str, 0, data->nl);
    str_tmp = ft_strsub(data->str, data->nl + 1, ft_strlen(data->str) - data->nl - 1);
    free(data->str);
    data->str = str_tmp;
    return (1);
}

int			get_next_line(const int fd, char **line)
{
    static t_read   data = {-1, NULL, -1, NULL};
    t_read          *p;

    p = &data;
    if (fd == -1 || line == NULL)
        return (-1);
    if (p->fd == -1)
        p->fd = fd;
    while (p->fd != fd)
    {
        if (!p->next)
            if ((p->next = malloc(sizeof(t_read))) == NULL)
                return (-1);
        p = p->next;
    }
    return (ft_readline(p, line));
}