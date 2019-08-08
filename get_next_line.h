/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:11:24 by jcanteau          #+#    #+#             */
/*   Updated: 2019/08/08 17:33:40 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include ".lib/libft.h"
# include <stdio.h>
# define BUFF_SIZE 32

typedef struct  s_read
{
    int             fd;
    char            *content;
    struct s_read   *next;
}   t_read;

int		get_next_line(const int fd, char **line);

#endif
