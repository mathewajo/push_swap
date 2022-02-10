/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:08:38 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:23:01 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a, t_all *all)
{
	t_node	*el;

	if (!a)
		return ;
	el = a->top;
	if (el->value > el->next->value)
		sa(a, 1, all);
	free_all(all, NULL, NULL);
}

void	sort_three(t_stack *a, t_all *all)
{
	int	one;
	int	two;
	int	three;

	if (!a || !all)
		error(all, 1, NULL, NULL);
	one = a->top->value;
	two = a->top->next->value;
	three = a->top->next->next->value;
	if (one > two && two < three && one < three)
		sa(a, 1, all);
	else if (one > two && two > three && one > three)
	{
		sa(a, 1, all);
		rra(a, 1, all);
	}
	else if (one > two && two < three && one > two)
		ra(a, 1, all);
	else if (one < two && two > three && one < three)
	{
		sa(a, 1, all);
		ra(a, 1, all);
	}
	else if (one < two && two > three && one > three)
		rra(a, 1, all);
}

void	prep_set(t_stack *a, t_stack *b, t_all *all)
{
	int	big;
	int	small;

	big = biggest(a);
	small = smallest(a);
	while (!is_on_top(a, small))
		bring_to_top(a, small, all);
	pb(a, b, 1, all);
	if (stack_length(a) > 3)
	{
		while (!is_on_top(a, big))
			bring_to_top(a, big, all);
		pb(a, b, 1, all);
	}
}

void	sort_more_three(t_stack *a, t_stack *b, t_all *all)
{
	int	s_len;

	s_len = stack_length(a);
	prep_set(a, b, all);
	sort_three(a, all);
	if (s_len == 5)
	{
		pa(b, a, 1, all);
		ra(a, 1, all);
	}
	pa(b, a, 1, all);
	if (stack_is_empty(all->a))
		error(all, 1, NULL, NULL);
	free_all(all, NULL, NULL);
}

int	small_cases(t_stack *a, t_stack *b, t_all *all)
{
	if (stack_length(a) == 1)
		free_all(all, NULL, NULL);
	else if (stack_length(a) == 2)
		sort_two(a, all);
	else if (stack_length(a) == 3)
	{
		sort_three(a, all);
		free_all(all, NULL, NULL);
	}
	else
		sort_more_three(a, b, all);
	if (stack_is_empty(all->a))
		error(all, 1, NULL, NULL);
	free_all(all, NULL, NULL);
	return (SUCCESS);
}
