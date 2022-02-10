/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:26:42 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:25:47 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_stack *s, int x, t_all *all)
{
	if (!s)
		return ;
	if (is_on_top(s, x))
		return ;
	if (where_middle(s, x) == 1)
	{
		while (!is_on_top(s, x))
			ra(s, 1, all);
	}
	else
	{
		while (!is_on_top(s, x))
			rra(s, 1, all);
	}
}

int	where_middle(t_stack *a, int value)
{
	t_node	*el;
	float	i;

	if (!a)
		return (-1);
	el = a->top;
	i = 1;
	while (el)
	{
		if (el->value == value)
		{
			if (i / (float)stack_length(a) <= 0.5)
				return (1);
			else
				return (2);
		}
		el = el->next;
		i++;
	}
	return (-1);
}

int	biggest(t_stack *a)
{
	int		biggest;
	t_node	*el;

	if (!a)
		return (0);
	el = a->top;
	biggest = el->value;
	while (el)
	{
		if (el->value > biggest)
			biggest = el->value;
		el = el->next;
	}
	return (biggest);
}

int	smallest(t_stack *a)
{
	int		smallest;
	t_node	*el;

	if (!a)
		return (0);
	el = a->top;
	smallest = el->value;
	while (el)
	{
		if (el->value < smallest)
			smallest = el->value;
		el = el->next;
	}
	return (smallest);
}

int	is_on_top(t_stack *a, int x)
{
	if (a->top->value == x)
		return (SUCCESS);
	return (ERROR);
}
