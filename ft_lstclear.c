/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:32:57 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/14 08:38:41 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*swaplst;
	t_list	*swaplst1;

	if ((lst == NULL) || (*del == NULL))
		return ;
	if (*lst != NULL)
	{
		swaplst = *lst;
		swaplst1 = swaplst;
		while (swaplst != NULL)
		{
			swaplst = swaplst->next;
			del(swaplst1->content);
			free(swaplst1);
			swaplst1 = swaplst;
		}
	}
	*lst = NULL;
}
