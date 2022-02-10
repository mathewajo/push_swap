/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarrbrrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:13:40 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:22:07 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_ro(t_stack *s)
{
	t_node	*p;
	t_node	*el;

	if (!s || !s->top || !s->top->next)
		return ;
	el = s->top;
	while (el->next)
	{
		p = el;
		el = el->next;
	}
	el->next = s->top;
	s->top = el;
	p->next = NULL;
}

void	rra(t_stack *a, int p, t_all *all)
{
	reverse_ro(a);
	if (p == 1)
		write(1, "rra\n", 4);
	all->action_count++;
}

void	rrb(t_stack *b, int p, t_all *all)
{
	reverse_ro(b);
	if (p == 1)
		write(1, "rrb\n", 4);
	all->action_count++;
}

void	rrr(t_stack *a, t_stack *b, int p, t_all *all)
{
	reverse_ro(a);
	reverse_ro(b);
	if (p == 1)
		write(1, "rrr\n", 4);
	all->action_count--;
}
