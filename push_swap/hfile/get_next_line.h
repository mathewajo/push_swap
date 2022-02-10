/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:31:27 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:19:34 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "push_swap.h"

# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line, t_all *all);
char	*gnl_strjoin(char *s1, char *s2, t_all *all);
int		ft_len(const char *s);

#endif