/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:06:40 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/07 14:21:42 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_slen(const char *s)
{
	long int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	long int	i;

	i = ft_slen(s);
	while (i >= 0)
	{
		if (((s[i] - (char)c) == 0) && (((char)c - s[i]) == 0))
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
