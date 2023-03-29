/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:01:28 by fporciel          #+#    #+#             */
/*   Updated: 2023/01/30 22:49:13 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	catbound;

	if ((dst == NULL) && (dstsize == 0))
		return (0);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if ((dstsize <= dstlen) || (dstsize == 0))
		return (srclen + dstsize);
	dst = dst + dstlen;
	catbound = dstsize - dstlen - 1;
	while ((*src != 0) && (catbound-- > 0))
		*dst++ = *src++;
	*dst = 0;
	return (dstlen + srclen);
}
