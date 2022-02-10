/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:58:39 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:18:50 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2, t_all *all)
{
	char	*single;
	size_t	i;
	size_t	j;
	size_t	l;

	single = (char *)malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1));
	if ((!s1 && !s2) || !(single))
		error(all, 1, NULL, NULL);
	i = 0;
	j = 0;
	l = ft_len(s1);
	while (i < l)
	{
		single[i] = s1[i];
		i++;
	}
	l = ft_len(s2);
	while (j < l)
	{
		single[i + j] = s2[j];
		j++;
	}
	single[i + j] = '\0';
	free(s1);
	return (single);
}

void	check_line(char *line, t_all *all)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isalpha(line[i]))
		{
			free(line);
			error(all, 1, NULL, NULL);
		}
		i++;
	}
}
