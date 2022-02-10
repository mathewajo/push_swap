/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:20:52 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:21:10 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_other_stack(t_stack *one, t_stack *two)
{
	t_node	*el;

	if (stack_is_empty(one))
		return ;
	el = one->top;
	if (stack_length(one) && stack_length(two))
	{
		one->top = one->top->next;
		el->next = two->top;
		two->top = el;
	}
	else if (!(stack_length(two)) && stack_length(one))
	{
		one->top = one->top->next;
		el->next = NULL;
		two->top = el;
	}
}

void	push_end(t_stack *s, int x, t_all *all)
{
	t_node	*el;
	t_node	*temp;

	el = (t_node *)malloc(sizeof(t_node));
	if (!el)
		error(all, 1, NULL, NULL);
	el->value = x;
	if (el == NULL)
	{
		exit(EXIT_FAILURE);
		return ;
	}
	if (!s->top)
	{
		el->next = NULL;
		s->top = el;
		return ;
	}
	temp = s->top;
	while (temp->next)
		temp = temp->next;
	temp->next = el;
	el->next = NULL;
}

void	push_end_plus_origin(t_stack *s, int x, t_node *ori, t_all *all)
{
	t_node	*el;
	t_node	*temp;

	el = (t_node *)malloc(sizeof(t_node));
	if (!el)
		error(all, 1, NULL, NULL);
	el->value = x;
	el->init_pos = ori;
	if (el == NULL)
	{
		exit(EXIT_FAILURE);
		return ;
	}
	if (!s->top)
	{
		el->next = NULL;
		s->top = el;
		return ;
	}
	temp = s->top;
	while (temp->next)
		temp = temp->next;
	temp->next = el;
	el->next = NULL;
}

void	pa(t_stack *one, t_stack *two, int p, t_all *all)
{
	if (stack_is_empty(one))
		return ;
	push_other_stack(one, two);
	if (p == 1)
		write(1, "pa\n", 3);
	all->action_count++;
}

void	pb(t_stack *one, t_stack *two, int p, t_all *all)
{
	if (stack_is_empty(one))
		return ;
	push_other_stack(one, two);
	if (p == 1)
		write(1, "pb\n", 3);
	all->action_count++;
}
