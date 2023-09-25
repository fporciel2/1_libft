/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:05:07 by fporciel          #+#    #+#             */
/*   Updated: 2023/09/25 06:24:13 by fedeporcus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
* This software is made available to anyone who wants to retrace the 
* author's learning path through the projects of school 42.
* Copyright (C) 2023  fporciel
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
* You can contact the author at: 
*- fporciel@student.42roma.it
*/

#include "./libft.h"
/*#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	strlen;

	strlen = 0;
	if (str)
	{
		while (str[strlen])
			strlen++;
	}
	return (strlen);
}*/

static size_t	ft_count_words(char *str, char del)
{
	size_t	count;
	size_t	num;

	count = 0;
	num = 0;
	while (str[count])
	{
		if ((str[count] != del)
			&& ((count == 0) || (str[count - 1] == del)))
			num++;
		count++;
	}
	return (num);
}

static char	**ft_clean_split(char **split, size_t words)
{
	size_t	count;

	count = 0;
	if (words == count)
		return (free(split), NULL);
	while (count < words)
	{
		free(split[count]);
		split[count] = NULL;
		count++;
	}
	free(split);
	return (NULL);
}

static char	*ft_create_string(char *split, char *str, char del)
{
	size_t	strlen;

	strlen = 0;
	while (str[strlen] && (str[strlen] != del))
		strlen++;
	split = malloc((strlen + 1) * sizeof(*split));
	if (split == NULL)
		return (NULL);
	strlen = 0;
	while (str[strlen] && (str[strlen] != del))
	{
		split[strlen] = str[strlen];
		strlen++;
	}
	split[strlen] = 0;
	return (split);
}

static char	**ft_fill_split(char **split, char *str, char del)
{
	size_t	count;
	ssize_t	words;

	count = 0;
	words = -1;
	while (str[count])
	{
		if ((str[count] != del)
			&& ((count == 0) || (str[count - 1] == del)))
		{
			words++;
			split[words] = NULL;
			split[words] = ft_create_string(split[words], &(str[count]), del);
			if (split[words] == NULL)
				return (ft_clean_split(split, words));
		}
		count++;
	}
	return (split);
}

char	**ft_split(char *str, char del)
{
	size_t	words_num;
	char	**split;

	if (str == NULL)
		return (NULL);
	words_num = ft_count_words(str, del);
	split = malloc((words_num + 1) * sizeof(*split));
	if (split == NULL)
		return (NULL);
	split = ft_fill_split(split, str, del);
	if (split == NULL)
		return (NULL);
	split[words_num] = NULL;
	return (split);
}
/*
int	main(int argc, char **argv)
{
	char	**arg_a;
	char	**arg_b;
	size_t	count;
	size_t	splitlen;

	write(1, argv[1], ft_strlen(argv[1]));
	write(1, "\n", 1);
	write(1, argv[2], ft_strlen(argv[2]));
	write(1, "\n\n", 2);
	arg_a = ft_split(argv[1], 32);
	if (arg_a == NULL)
		return ((int)write(1, "Failed split\n", 13));
	arg_b = ft_split(argv[2], 32);
	if (arg_b == NULL)
		return ((int)write(1, "Failed split\n", 13));
	count = 0;
	while (arg_a[count])
	{
		printf("%s\n", arg_a[count]);
		count++;
	}
	splitlen = 0;
	while (splitlen < count)
	{
		free(arg_a[splitlen]);
		arg_a[splitlen] = NULL;
		splitlen++;
	}
	free(arg_a);
	arg_a = NULL;
	count = 0;
	while (arg_b[count])
	{
		printf("%s\n", arg_b[count]);
		count++;
	}
	splitlen = 0;
	while (splitlen < count)
	{
		free(arg_b[splitlen]);
		arg_b[splitlen] = NULL;
		splitlen++;
	}
	free(arg_b);
	arg_b = NULL;
	return (argc);
}*/
