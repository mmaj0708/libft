/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:17:58 by mmaj              #+#    #+#             */
/*   Updated: 2019/10/21 18:31:44 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		taille(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	size_t			i;
	char			*str;

	if (!(str = ft_calloc(sizeof(char) * (taille(n) + 1), 1)))
		return (NULL);
	nb = n;
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	i = taille(n) - 1;
	if (n == 0)
		str[i] = 48;
	while (nb != 0)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	return (str);
}
