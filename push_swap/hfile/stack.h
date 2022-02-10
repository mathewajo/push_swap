/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajomathew <ajomathew@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:37:10 by coder             #+#    #+#             */
/*   Updated: 2022/01/24 09:20:11 by ajomathew        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_node
{
	int				value;
	bool			keep;
	struct s_node	*init_pos;
	struct s_node	*next;
	int				i;
}					t_node;

typedef struct s_all
{
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_node	*f_a;
	struct s_node	*f_b;
	int				size_a;
	int				size_b;
	int				max;
	int				max_size;
	int				action_count;
	char			*line;
	char			*s;
}					t_all;

typedef struct s_stack
{
	struct s_node	*top;
}					t_stack;

typedef struct s_params
{
	t_node	*el;
	t_node	*best;
	int		c_a;
	int		c_b;
	int		min_move;
	int		total;
	int		action_b;
	int		min_a;
	int		min_b;
}			t_params;

t_node	*ft_lstnew(void);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **alst, t_node *new);
void	ft_lstadd_front(t_node **alst, t_node *new);
void	*ft_allset(void *b, int c, size_t len);
void	*ft_allcpy(void *dst, const void *src, size_t n);
void	ft_lstclear(t_node **lst);
void	ft_lstdelone(t_node *lst);

#endif