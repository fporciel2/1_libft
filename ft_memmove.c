/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:23:13 by fporciel          #+#    #+#             */
/*   Updated: 2023/01/26 09:35:55 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	buff;
	size_t			i;

	if (!(dst) && !(src))
		return (NULL);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			buff = *((unsigned char *)src + i);
			*((unsigned char *)dst + i) = buff;
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			buff = *((unsigned char *)src + (len - 1));
			*((unsigned char *)dst + (len - 1)) = buff;
			len--;
		}
	}
	return (dst);
}
