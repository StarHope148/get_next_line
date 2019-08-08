/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:57:11 by jcanteau          #+#    #+#             */
/*   Updated: 2019/08/08 19:26:38 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*newstr;

	if (s == NULL)
		return (NULL);
	newstr = (char*)malloc(sizeof(char) * len + 1);
	if (newstr == NULL)
		return (newstr);
	i = 0;
	while (i < len)
	{
		newstr[i] = s[start];
		start++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
