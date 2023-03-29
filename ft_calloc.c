/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:21:34 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/07 16:23:19 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_callocmemset(void *cal, int c, size_t countsize)
{
	size_t	i;

	i = 0;
	while (i < countsize)
	{
		*((unsigned char *)cal + i) = (unsigned int)c;
		i++;
	}
	return (cal);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;

	if ((count == SIZE_MAX) || (size == SIZE_MAX))
		return (NULL);
	cal = (void *)malloc(count * size);
	if (cal == NULL)
		return (NULL);
	ft_callocmemset(cal, 0, (count * size));
	return (cal);
}
