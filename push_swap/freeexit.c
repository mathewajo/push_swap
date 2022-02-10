/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeexit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:21:41 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:24:40 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	t_node	*el;

	el = s->top;
	while (el)
	{
		s->top = s->top->next;
		free(el);
		el = NULL;
		el = s->top;
	}
	free(s);
	s = NULL;
}

void	free_all(t_all *all, int *min_a, int *min_b)
{
	free_stack(all->a);
	free_stack(all->b);
	if (all->line)
		free(all->line);
	if (all->s)
		free(all->s);
	free(all);
	all = NULL;
	if (!min_a)
	{
		free (min_a);
		min_a = NULL;
	}
	if (!min_a)
	{
		free (min_b);
		min_b = NULL;
	}
	exit (EXIT_SUCCESS);
}

void	error(t_all *all, int p, int *min_a, int *min_b)
{
	if (p == 1)
		write(2, "error\n", 6);
	free_all(all, min_a, min_b);
	exit (EXIT_FAILURE);
}
