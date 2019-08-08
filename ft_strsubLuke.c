/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubLuke.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:44:08 by lperrey           #+#    #+#             */
/*   Updated: 2019/08/08 19:22:54 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strsubLuke(char const *s, unsigned int start, size_t len)
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
