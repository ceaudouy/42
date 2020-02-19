/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:06:09 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/17 12:48:23 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (lst && f)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (0);
		tmp = f(lst);
		new = tmp;
		while (lst->next)
		{
			lst = lst->next;
			if (!(tmp->next = f(lst)))
			{
				free(tmp->next);
				return (NULL);
			}
			tmp = tmp->next;
		}
		return (new);
	}
	return (NULL);
}
