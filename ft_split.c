/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:20:26 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/06 13:58:43 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freemem(char	**split, size_t	i)
{
	while (i > 0)
	{
		i--;
		free(split[i]);
	}
	free(split);
	return (NULL);
}

static size_t	ft_splitlen(char const *s, char c)
{
	size_t	splitlen;
	size_t	i;

	splitlen = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			splitlen++;
			while ((s[i] != c) && (s[i] != 0))
				i++;
		}
		else
			i++;
	}
	return (splitlen);
}

static char	*ft_splut(char *split, const char *s, size_t i, size_t sublen)
{
	int	j;

	j = 0;
	while (sublen > 0)
	{
		split[j] = s[i - sublen];
		j++;
		sublen--;
	}
	split[j] = 0;
	return (split);
}

static char	**ft_splitt(char const *s, char c, char **split, size_t splitlen)
{
	size_t	sublen;
	size_t	i;
	size_t	j;

	i = 0;
	sublen = 0;
	j = 0;
	while (j < splitlen)
	{
		while ((s[i] == c) && (s[i] != 0))
			i++;
		while ((s[i] != c) && (s[i] != 0))
		{
			sublen++;
			i++;
		}
		split[j] = (char *)malloc(sizeof(char) * (sublen + 1));
		if (split == NULL)
			return (ft_freemem(split, i));
		ft_splut(split[j], s, i, sublen);
		sublen = 0;
		j++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	splitlen;

	if (s == NULL)
		return (NULL);
	splitlen = ft_splitlen(s, c);
	split = (char **)malloc(sizeof(char *) * (splitlen + 1));
	if (split == NULL)
		return (NULL);
	split = ft_splitt(s, c, split, splitlen);
	return (split);
}
