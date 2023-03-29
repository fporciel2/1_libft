/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:55:55 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/07 13:54:46 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((((unsigned char *)s)[i] - (unsigned char)c) == 0)
				&& (((unsigned char)c - ((unsigned char *)s)[i]) == 0))
			return (((unsigned char *)s) + i);
		i++;
	}
	return (NULL);
}
