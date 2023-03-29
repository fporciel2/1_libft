/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:25 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/09 15:32:14 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

static char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	s1len;
	size_t	s2len;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (strjoin == NULL)
		return (NULL);
	strjoin = ft_strcpy(strjoin, s1);
	strjoin = ft_strcat(strjoin, s2);
	return (strjoin);
}
