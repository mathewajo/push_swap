/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:52:54 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:18:02 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	actionss(char *action, t_all *all)
{
	if (!ft_strcmp(action, "rb"))
		rb(all->b, 0, all);
	else if (!ft_strcmp(action, "rr"))
		rr(all->a, all->b, 0, all);
	else if (!ft_strcmp(action, "rra"))
		rra(all->a, 0, all);
	else if (!ft_strcmp(action, "rrb"))
		rra(all->b, 0, all);
	else if (!ft_strcmp(action, "rrr"))
		rrr(all->a, all->b, 0, all);
	else if (!ft_strcmp(action, "sa"))
		sa(all->a, 0, all);
	else if (!ft_strcmp(action, "sb"))
		sb(all->a, 0, all);
	else if (!ft_strcmp(action, "ss"))
		ss(all->a, all->b, 0, all);
	else if (!ft_strcmp(action, "pa"))
		pa(all->b, all->a, 0, all);
	else if (!ft_strcmp(action, "pb"))
		pb(all->a, all->b, 0, all);
	else if (!ft_strcmp(action, "ra"))
		ra(all->a, 0, all);
	else
		error(all, 1, NULL, NULL);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	char	*action;

	all = init_all();
	if (argc >= 2)
	{
		read_args(argc, argv, all);
		while (get_next_line(0, &action, all))
		{
			actionss(action, all);
			free(action);
			action = NULL;
		}
		if (is_sorted_stack(all->a) && stack_is_empty(all->b))
		{
			write(1, "OK\n", 3);
			free_all(all, NULL, NULL);
		}
		else
		{
			write(1, "KO\n", 3);
			error(all, 0, NULL, NULL);
		}
	}
	error(all, 0, NULL, NULL);
}
