/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:36:05 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:24:59 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_is_empty(t_stack *s)
{
	if (s->top == NULL)
		return (true);
	return (false);
}

int	stack_length(t_stack *s)
{
	int		length;
	t_node	*el;

	if (!s)
		return (0);
	length = 0;
	el = s->top;
	while (el)
	{
		length++;
		el = el->next;
	}
	return (length);
}

t_all	*init_all(void)
{
	t_all	*all;
	t_stack	*a;
	t_stack	*b;

	all = (t_all *)malloc(sizeof(t_all));
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!all || !a || !b)
		exit (EXIT_FAILURE);
	a->top = NULL;
	b->top = NULL;
	all->action_count = 0;
	all->a = a;
	all->b = b;
	all->line = NULL;
	all->s = NULL;
	return (all);
}

int	push_args(char	*st, t_all *all, int *args)
{
	long	x;
	bool	s;

	s = true;
	while (*st)
	{
		if (s && *st != ' ')
		{
			x = push_atoi(st, all);
			if (x > INT_MAX || x < INT_MIN)
				error(all, 1, NULL, NULL);
			push_end(all->a, x, all);
			(*args)++;
			check_duplicates(all);
		}
		s = *st == ' ';
		st++;
	}
	return (SUCCESS);
}

int	read_args(int argc, char **argv, t_all *all)
{
	int	args;
	int	i;

	i = 1;
	args = 0;
	while (i < argc)
	{
		push_args(argv[i], all, &args);
		i++;
	}
	if (!(all->a->top))
		error(all, 0, NULL, NULL);
	return (args);
}
