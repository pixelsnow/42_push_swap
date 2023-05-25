/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:12 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 22:14:51 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	int				rank;
	int				data;
}					t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}					t_stack;

typedef struct s_push_swap
{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_push_swap;

t_node		*create_elem(int data);
t_stack		*create_stack(void);
t_push_swap	*create_push_swap(void);

void		push(t_stack *s, t_node *new);
t_node		*pop(t_stack *s);
void		unshift(t_stack *s, t_node *new);
t_node		*shift(t_stack *s);

void		delete_stack(t_stack **s);
void		delete_push_swap(t_push_swap **stacks);
void		delete_split(char	**splits);

void		print_push_swap(t_push_swap *stacks);

void		sa(t_push_swap *stacks);
void		sb(t_push_swap *stacks);
void		ss(t_push_swap *stacks);

void		pa(t_push_swap *stacks);
void		pb(t_push_swap *stacks);

void		ra(t_push_swap *stacks);
void		rb(t_push_swap *stacks);
void		rr(t_push_swap *stacks);

void		rra(t_push_swap *stacks);
void		rrb(t_push_swap *stacks);
void		rrr(t_push_swap *stacks);

int			parse_input(int ac, char **av, t_push_swap *stacks);

void		sort_two(t_push_swap *stacks);
void		sort_three(t_push_swap *stacks);

#endif
