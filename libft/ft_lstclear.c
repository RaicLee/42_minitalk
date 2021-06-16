/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:12:09 by jealee            #+#    #+#             */
/*   Updated: 2020/12/26 22:51:02 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pointer;

	if (lst != NULL && del != NULL)
	{
		while (*lst)
		{
			pointer = *lst;
			del(pointer->content);
			*lst = pointer->next;
			free(pointer);
		}
	}
}
