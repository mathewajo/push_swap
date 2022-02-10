/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarbrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:35:57 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:21:32 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *s)
{
	t_node	*last;
	t_node	*tmp;

	if (!s || !s->top || !s->top->next)
		return ;
	last = last_element(s);
	tmp = s->top;
	s->top = s->top->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	ra(t_stack *a, int p, t_all *all)
{
	if (!a || !all)
		return ;
	rotate(a);
	if (p == 1)
		write(1, "ra\n", 3);
	all->action_count++;
}

void	rb(t_stack *b, int p, t_all *all)
{
	if (!b || !all)
		return ;
	rotate(b);
	if (p == 1)
		write(1, "rb\n", 3);
	all->action_count++;
}

void	rr(t_stack *a, t_stack *b, int p, t_all *all)
{
	if (!a || !b || !all)
		return ;
	rotate(a);
	rotate(b);
	if (p == 1)
		write(1, "rr\n", 3);
	all->action_count++;
}

t_node	*last_element(t_stack *s)
{
	t_node	*el;

	if (!s || !s->top)
		return (NULL);
	el = s->top;
	while (el->next)
		el = el->next;
	return (el);
}
