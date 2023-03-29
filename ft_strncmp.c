/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:39:43 by fporciel          #+#    #+#             */
/*   Updated: 2023/01/26 12:31:35 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	if ((((unsigned char *)s1)[i] == 0) || (((unsigned char *)s2)[i] == 0))
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	while ((i < n) && (((unsigned char *)s1)[i] != 0)
			&& (((unsigned char *)s2)[i] != 0))
	{
		if ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]) != 0)
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if (i < n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (((unsigned char *)s1)[i - 1] - ((unsigned char *)s2)[i - 1]);
}
