/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:19:48 by mmaj              #+#    #+#             */
/*   Updated: 2019/10/25 16:41:18 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*d;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) - 1)
		return (d = ft_calloc(1, 1));
	if (!(d = (char *)ft_calloc(
		len <= (ft_strlen(s) - start) ? (len + 1) :
		ft_strlen(s) - start + 1, 1)))
		return (NULL);
	while (i < len && s[start + i])
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = 0;
	return (d);
}
