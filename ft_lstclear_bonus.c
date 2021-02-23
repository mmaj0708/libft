/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:30:24 by mmaj              #+#    #+#             */
/*   Updated: 2019/10/22 19:48:29 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list **l;

	if (!*lst)
		return ;
	l = &((*lst)->next);
	if (*lst)
		ft_lstclear(l, del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
