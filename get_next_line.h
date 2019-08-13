/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:11:24 by jcanteau          #+#    #+#             */
/*   Updated: 2019/08/13 17:42:25 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>
# define BUFF_SIZE 32

typedef struct	s_read
{
	int				fd;
	char			*str;
	int				nl;
	int				ret;
	int				state;
	struct s_read	*next;
}				t_read;

int				get_next_line(const int fd, char **line);

#endif
