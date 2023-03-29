/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:03:31 by fporciel          #+#    #+#             */
/*   Updated: 2023/01/31 04:51:27 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((haystack == NULL) && (needle == NULL))
		return (NULL);
	if ((*needle == 0) || (needle == haystack))
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] != 0)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && ((i + j) < len))
		{
			if ((haystack[i + j] == 0) && (needle[j] == 0))
				return ((char *)&haystack[i]);
			j++;
		}
		if (needle[j] == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
