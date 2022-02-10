/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:15:20 by coder             #+#    #+#             */
/*   Updated: 2022/02/04 13:35:39 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hfile/push_swap.h"

void	more_slove(t_all *all)
{
	t_stack		*cpy;
	t_params	params;

	params = init_params(all);
	cpy = cpy_stack(all->a, all, &params);
	bubble_sort_cpy(cpy);
	set_target_index_cpy(cpy);
	set_target_index(cpy);
	free_stack(cpy);
	set_keep(all);
	push_keep_false_b(all);
	while (!stack_is_empty(all->b))
	{
		params.el = all->b->top;
		evaluate_actions(all, &params);
		sort(all, &params);
	}
	if (!(is_on_top(all->a, smallest(all->a))))
		bring_to_top(all->a, smallest(all->a), all);
	if (stack_is_empty(all->a))
		error(all, 1, NULL, NULL);
	free_all(all, NULL, NULL);
}

int	main(int argc, char **argv)
{
	int		read_a;
	t_all	*all;

	if (argc < 2)
		return (0);
	all = init_all();
	if (argc >= 2)
	{
		read_a = read_args(argc, argv, all);
		if (stack_is_empty(all->a))
			error(all, 1, NULL, NULL);
		if (is_sorted_stack(all->a))
			free_all(all, NULL, NULL);
		if (read_a <= 5)
			small_cases(all->a, all->b, all);
		else
			more_slove(all);
	}
	error(all, 0, NULL, NULL);
	return (0);
}
