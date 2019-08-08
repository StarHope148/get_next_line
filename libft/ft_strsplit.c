/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:32:07 by jcanteau          #+#    #+#             */
/*   Updated: 2018/11/28 16:05:05 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		nb_word(char *str, char c)
{
	int state;
	int count;

	state = 0;
	count = 0;
	while (*str)
	{
		if (*str == c)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static int		w_len(char *str, int i, char c)
{
	int total;

	total = 0;
	while (str[i] != c && str[i])
	{
		total++;
		i++;
	}
	return (total);
}

static int		is_word(char *str, int i, char c)
{
	if (str[i] != (char)c && str[i])
		return (1);
	else
		return (0);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		i;
	int		a;
	int		b;

	i = -1;
	a = -1;
	if (str == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * nb_word((char *)str, c) + 1)))
		return (NULL);
	while (str[++i])
		if (str[i] != (char)c && str[i])
		{
			b = 0;
			if (!(tab[++a] = (char *)malloc(sizeof(char)
							* w_len((char *)str, i, c) + 1)))
				return (NULL);
			while (is_word((char *)str, i, c))
				tab[a][b++] = str[i++];
			i--;
			tab[a][b] = '\0';
		}
	tab[++a] = NULL;
	return (tab);
}
