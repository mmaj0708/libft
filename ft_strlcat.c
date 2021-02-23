/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:24:21 by mmaj              #+#    #+#             */
/*   Updated: 2019/10/17 19:50:25 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*d;

	i = 0;
	j = 0;
	d = (char *)dst;
	while (d[i])
		i++;
	while (src[j])
		j++;
	k = i + j;
	if (dstsize <= i)
		return ((i + j) - (i - dstsize));
	j = 0;
	while (src[j] && (i < dstsize - 1))
	{
		d[i] = src[j];
		j++;
		i++;
	}
	d[i] = '\0';
	return (k);
}
