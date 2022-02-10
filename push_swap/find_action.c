/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:51:15 by coder             #+#    #+#             */
/*   Updated: 2022/02/07 14:23:02 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	optimize_actions(int n_a, int n_b)
{
	if (n_a > 0 && n_b > 0)
		return (abs_value(n_a) + abs_value(n_b) - min(n_a, n_b));
	else if (n_a < 0 && n_b < 0)
		return (abs_value(n_a) + abs_value(n_b) + max(n_a, n_b));
	else
		return (abs_value(n_a) + abs_value(n_b));
	return (SUCCESS);
}

void	init_variables(int *i, int *pos, bool *end)
{
	*i = 1;
	*pos = 0;
	*end = false;
}

int	where_to_insert(t_stack *sta, int x, t_node *tmp, t_node *prev)
{
	int			i;
	int			pos;
	bool		end;

	init_variables(&i, &pos, &end);
	while (prev && !end)
	{
		if (tmp == NULL)
		{
			tmp = sta->top;
			end = true;
		}
		if ((x > prev->i && x < tmp->i)
			|| (prev->i > tmp->i && (x < tmp->i || x > prev->i)))
			pos = i;
		i++;
		prev = tmp;
		tmp = tmp->next;
	}
	if (pos > stack_length(sta) / 2)
		pos -= stack_length(sta);
	return (pos);
}

t_node	*evaluate_actions(t_all *all, t_params *params)
{
	t_node	*tmp;
	t_node	*prev;

	params->c_b = 0;
	params->min_move = 0xFFFFFFF;
	while (params->el)
	{
		tmp = all->a->top->next;
		prev = all->a->top;
		params->c_a = where_to_insert(all->a, params->el->i, tmp, prev);
		params->action_b = params->c_b;
		if (params->c_b > stack_length(all->b) / 2)
			params->action_b -= stack_length(all->b);
		params->total = optimize_actions(params->c_a, params->action_b);
		if (params->total < params->min_move)
		{
			params->min_move = params->total;
			params->best = params->el;
			params->min_a = params->c_a;
			params->min_b = params->action_b;
		}
		params->el = params->el->next;
		params->c_b++;
	}
	return (params->best);
}
