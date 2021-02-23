/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:23:53 by mmaj              #+#    #+#             */
/*   Updated: 2019/10/25 16:27:11 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_str_superlen(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (!(*str == c) && *str)
	{
		count++;
		str++;
	}
	return (count);
}

static const char	*saut_de_biche(char const *str, char c)
{
	if (*str)
	{
		str++;
		while (!(*(str - 1) == c) && !(*str == c))
		{
			if (!(*str))
				return (0);
			str++;
		}
		return (str);
	}
	return (0);
}

static size_t		compte_strs(char const *str, char c)
{
	size_t count;

	count = 0;
	while (*str)
	{
		if ((!(*str == c) && (*(str + 1) == c)) ||
			(!(*str == c) && !(*(str + 1))))
			count++;
		str++;
	}
	return (count);
}

static void			*free_tabstr(char **tab, size_t pos)
{
	size_t i;

	i = 0;
	while (i < pos)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	nb_strs;

	if (!s || !(split = malloc(sizeof(char*) * (compte_strs(s, c) + 1))))
		return (NULL);
	nb_strs = compte_strs(s, c);
	i = 0;
	while (i < nb_strs)
	{
		while (*s == c)
			s++;
		j = -1;
		if (!(split[i] = malloc(sizeof(char) * (ft_str_superlen(s, c) + 1))))
			return (free_tabstr(split, i));
		while (++j < ft_str_superlen(s, c))
			split[i][j] = s[j];
		split[i][j] = 0;
		i++;
		s = saut_de_biche(s, c);
	}
	split[i] = 0;
	return (split);
}
