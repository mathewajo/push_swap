/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:17:03 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:19:55 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "stack.h"
# define ERROR 0
# define SUCCESS 1

void		pushSwap(char *list);
int			checkArg(char *arg);
void		ra(t_stack *a, int print, t_all *all);
void		rb(t_stack *b, int print, t_all *all);
void		sa(t_stack *a, int print, t_all *all);
void		sb(t_stack *b, int print, t_all *all);
void		ss(t_stack *a, t_stack *b, int print, t_all *all);
void		rr(t_stack *a, t_stack *b, int print, t_all *all);
void		rra(t_stack *a, int print, t_all *all);
void		rrb(t_stack *b, int print, t_all *all);
void		rrr(t_stack *a, t_stack *b, int print, t_all *all);
void		pa(t_stack *one, t_stack *two, int print, t_all *all);
void		pb(t_stack *one, t_stack *two, int print, t_all *all);

long		push_atoi(char *str, t_all *all);
t_stack		*cpy_stack(t_stack *sta, t_all *all, t_params *params);
int			find_duplicate_small(t_stack *a);
int			ft_isalpha(int c);
int			is_sorted_stack(t_stack *a);
int			min(int x, int y);
int			max(int x, int y);
int			is_on_top(t_stack *a, int x);
int			where_middle(t_stack *a, int value);
t_node		*last_element(t_stack *sta);
int			read_args(int argc, char **argv, t_all *all);
void		push_end(t_stack *sta, int x, t_all *all);
void		check_duplicates(t_all *all);
void		free_stack(t_stack *sta);
void		error(t_all *all, int print, int *min_a, int *min_b);
void		free_all(t_all *all, int *min_a, int *min_b);

bool		stack_is_empty(t_stack *sta);
int			stack_length(t_stack *sta);
t_all		*init_all(void);
void		push_end_plus_origin(t_stack *sta, int x, t_node *ori, t_all *m);

void		more_slove(t_all *all);
t_params	init_params(t_all *all);
void		bring_to_top(t_stack *sta, int x, t_all *all);
void		sort_more_three(t_stack *a, t_stack *b, t_all *all);
void		prep_set(t_stack *a, t_stack *b, t_all *all);
int			small_cases(t_stack *a, t_stack *b, t_all *all);
void		sort_two(t_stack *a, t_all *all);
void		sort_three(t_stack *a, t_all *all);
int			biggest(t_stack *a);
int			smallest(t_stack *a);
t_stack		*bubble_sort_cpy(t_stack *cpy);
void		set_target_index_cpy(t_stack *cpy);
void		set_target_index(t_stack *sta);
int			largest_keep_a(t_node *elem, t_stack *stack, bool define);
void		set_keep(t_all *all);
void		push_keep_false_b(t_all *all);
t_node		*evaluate_actions(t_all *all, t_params *params);
int			abs_value(int x);
int			where_to_insert(t_stack *s, int x, t_node *t, t_node *p);
int			optimize_actions(int count_for_a, int count_for_b);
int			sort(t_all *all, t_params *params);

#endif