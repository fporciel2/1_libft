/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:07:09 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/07 14:52:38 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_srclen(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	i;

	s = ft_srclen(src);
	if (dstsize == 0)
		return (s);
	i = 0;
	if (s == 0)
		dst[i] = src[i];
	while ((src[i] != 0) && (i < (dstsize - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	if (s < dstsize)
		dst[i] = src[i];
	else
		dst[i] = 0;
	return (s);
}
