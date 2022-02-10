/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sasbss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:52:48 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:22:39 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_stack *s)
{
	t_node	*el;
	t_node	*se;

	if (!s)
		return ;
	if (stack_length(s) >= 2)
	{
		el = s->top;
		se = s->top->next->next;
		s->top = s->top->next;
		s->top->next = el;
		el->next = se;
	}
}

void	sa(t_stack *a, int p, t_all *all)
{
	if (!a || !all)
		return ;
	swap_ab(a);
	if (p == 1)
		write(1, "sa\n", 3);
	all->action_count++;
}

void	sb(t_stack *b, int p, t_all *all)
{
	if (!b || !all)
		return ;
	swap_ab(b);
	if (p == 1)
		write(1, "sb\n", 3);
	all->action_count++;
}

void	ss(t_stack *a, t_stack *b, int p, t_all *all)
{
	if (!a || !b || !all)
		return ;
	swap_ab(a);
	swap_ab(b);
	if (p == 1)
		write(1, "ss\n", 3);
	all->action_count++;
}
