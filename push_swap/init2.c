/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:03:24 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:25:27 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_duplicate_small(t_stack *a)
{
	int		i;
	t_node	*el;
	t_node	*tmp;

	i = 0;
	tmp = a->top;
	while (tmp->next)
	{
		el = tmp->next;
		while (el)
		{
			if (tmp->value == el->value)
			{
				i++;
				break ;
			}
			el = el->next;
		}
		tmp = tmp->next;
	}
	return (i);
}

int	is_sorted_stack(t_stack *a)
{
	t_node	*el;

	el = a->top;
	while (a->top && el->next)
	{
		if (el->next->value < el->value)
			return (ERROR);
		el = el->next;
	}
	return (SUCCESS);
}

void	check_duplicates(t_all *all)
{
	t_node	*el1;
	t_node	*el2;

	el1 = all->a->top;
	el2 = all->a->top;
	while (el2)
	{
		el1 = all->a->top;
		while (el1)
		{
			if (el1->value == el2->value && el1 != el2)
				error(all, 1, NULL, NULL);
			el1 = el1->next;
		}
		el2 = el2->next;
	}
}

int	abs_value(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_params	init_params(t_all *all)
{
	t_params	params;

	params.c_a = 0;
	params.c_b = 0;
	params.el = all->b->top;
	params.best = NULL;
	params.min_a = 0;
	params.min_b = 0;
	params.min_move = 0xFFFFFFF;
	params.action_b = 0;
	params.total = 0;
	return (params);
}
