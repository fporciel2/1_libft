/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:06:11 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/13 13:42:10 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*index;

	if (lst == NULL)
		return (0);
	i = 0;
	index = lst;
	while (index != NULL)
	{
		index = index->next;
		i++;
	}
	return (i);
}
