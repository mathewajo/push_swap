/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:38:22 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:27:17 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	push_atoi(char *str, t_all *all)
{
	long	i;
	long	max;
	long	sign;
	long	result;

	i = 0;
	max = 0;
	sign = 1;
	result = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (ft_isalpha(str[i]) || max >= 1)
			error(all, 1, NULL, NULL);
		if (str[i] == '-')
			sign = -sign;
		max++;
		i++;
	}
	if (!str[i] || !ft_isdigit(str[i]))
		error(all, 1, NULL, NULL);
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (str[i] && !(ft_isdigit(str[i])) && str[i] != ' ')
		error(all, 1, NULL, NULL);
	return (result * sign);
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
