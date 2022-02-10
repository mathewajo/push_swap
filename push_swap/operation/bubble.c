/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:07:55 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:20:48 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*cpy_stack(t_stack *sta, t_all *all, t_params *params)
{
	t_stack	*cpy;
	t_node	*read;

	if (!sta)
		return (NULL);
	cpy = (t_stack *)malloc(sizeof(t_stack));
	read = sta->top;
	if (!cpy)
		error(all, 1, &params->min_a, &params->min_b);
	read = sta->top;
	cpy->top = NULL;
	while (read)
	{
		push_end_plus_origin(cpy, read->value, read, all);
		read = read->next;
	}
	return (cpy);
}

void	bubble_swap(t_node **ori, t_node **tmplst, t_node **elem, int *t)
{
	*t = (*elem)->value;
	*ori = (*elem)->init_pos;
	(*elem)->value = (*tmplst)->value;
	(*elem)->init_pos = (*tmplst)->init_pos;
	(*tmplst)->value = (*t);
	(*tmplst)->init_pos = *ori;
}

t_stack	*bubble_sort_cpy(t_stack *cpy)
{
	int		temp;
	t_node	*origin;
	t_node	*tmplst;
	t_node	*elem;

	tmplst = cpy->top;
	elem = cpy->top;
	origin = cpy->top->init_pos;
	temp = cpy->top->value;
	while (elem)
	{
		while (tmplst)
		{
			if (elem->value > tmplst->value)
				bubble_swap(&origin, &tmplst, &elem, &temp);
			tmplst = tmplst->next;
		}
		elem = elem->next;
		tmplst = elem;
	}
	return (cpy);
}

void	set_target_index_cpy(t_stack *cpy)
{
	t_node	*elem;
	int		index;

	elem = cpy->top;
	index = 0;
	while (elem)
	{
		elem->i = index;
		elem = elem->next;
		index++;
	}
}

void	set_target_index(t_stack *sta)
{
	t_node	*elem;

	elem = sta->top;
	while (elem)
	{
		elem->init_pos->i = elem->i;
		elem = elem->next;
	}
}
