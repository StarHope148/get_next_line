/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:03:24 by jcanteau          #+#    #+#             */
/*   Updated: 2019/08/08 19:16:49 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if ((new = (char *)ft_memalloc(sizeof(char) * (size + 1))) != NULL)
	{
		new[size + 1] = '\0';
		return (new);
	}
	else
		return (NULL);
}
