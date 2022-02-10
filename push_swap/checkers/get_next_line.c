/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:58:29 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:18:29 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_hasnewline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_newline(char *s, t_all *all)
{
	char	*new_line;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!(new_line))
		error(all, 1, NULL, NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new_line[i] = s[i];
		i++;
	}
	new_line[i] = '\0';
	all->line = new_line;
	return (new_line);
}

char	*ft_prep_s(char *s)
{
	int		i;
	int		j;
	char	*clean_s;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	clean_s = (char *)malloc(sizeof(char) * (ft_len(s) - i + 1));
	if (!clean_s)
		return (NULL);
	i++;
	while (s[i])
		clean_s[j++] = s[i++];
	clean_s[j] = '\0';
	free(s);
	return (clean_s);
}

int	free_buffer(char *buffer)
{
	free(buffer);
	return (-1);
}

int	get_next_line(int fd, char **line, t_all *all)
{
	static char	*s;
	int			b_read;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE < 1 || !line || !buffer)
		error(all, 1, NULL, NULL);
	b_read = BUFFER_SIZE;
	while (b_read != 0 && !(ft_hasnewline(s)))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free_buffer(buffer));
		buffer[b_read] = '\0';
		s = gnl_strjoin(s, buffer, all);
	}
	free(buffer);
	*line = ft_newline(s, all);
	s = ft_prep_s(s);
	all->s = s;
	if (b_read == 0)
		return (ERROR);
	return (SUCCESS);
}
