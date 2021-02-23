/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:12:57 by mmaj              #+#    #+#             */
/*   Updated: 2019/10/25 16:28:59 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char const c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			j;
	int			k;
	char		*res;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	if (s1[i] == '\0')
		return ((char*)s1);
	while (ft_isset(set, s1[i]) == 1 && s1[i])
		i++;
	j = ft_strlen(s1) - 1;
	while (ft_isset(set, s1[j]) == 1 && j > i)
		j--;
	if (!(res = (char *)ft_calloc((j - i + 2), sizeof(char))))
		return (NULL);
	while (i <= j)
		res[k++] = s1[i++];
	return (res);
}
