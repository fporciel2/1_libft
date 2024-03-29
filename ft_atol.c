/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:03:22 by fporciel          #+#    #+#             */
/*   Updated: 2023/10/03 11:09:59 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
* 'atoi' implementation that handles long long int type.
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

#include "libft.h"

static long long	ft_power(long long base, long long exp)
{
	long long	power;
	long long	cpower;

	if ((base == 0) && (exp != 0))
		return (0);
	else if (exp == 0)
		return (1);
	else
	{
		power = 1;
		cpower = base;
		while (exp)
		{
			if (exp & 1)
				power *= cpower;
			cpower *= cpower;
			exp >>= 1;
		}
	}
	return (power);
}

static long long	ft_chkatol(char *nptr)
{
	long long	i;

	i = 0;
	while (!ft_isdigit(nptr[i]) && (nptr[i] != 0))
	{
		if (!((nptr[i] == 43) || (nptr[i] == 45))
			&& !((nptr[i] == 32)
				|| ((nptr[i] >= 9) && (nptr[i] <= 13))))
			return (0);
		if ((nptr[i] == 45) && (ft_isdigit(nptr[i + 1])))
			return (-1);
		if (((nptr[i] == 43) || (nptr[i] == 45)) && (!ft_isdigit(nptr[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atol(char *nptr)
{
	long long	i;
	long long	j;
	long long	num;
	long long	exp;

	i = 0;
	num = 0;
	j = 0;
	while (!ft_isdigit(nptr[i]) && (nptr[i] != 0))
		i++;
	j = i;
	while (ft_isdigit(nptr[i]))
		i++;
	exp = ((i - j) - 1);
	while (j < i)
	{
		num = num + ((nptr[j] - 48) * ft_power(10, exp));
		exp--;
		j++;
	}
	return (num * ft_chkatol(nptr));
}
