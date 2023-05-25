/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:55:31 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 15:42:09 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_from_stack_to_stack(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	tmp = pop(from);
	if (!tmp)
		return ;
	push(to, tmp);
}

void	pa(t_push_swap *stacks)
{
	move_from_stack_to_stack(stacks->b, stacks->a);
	write(1, "pa\n", 3);
}

void	pb(t_push_swap *stacks)
{
	move_from_stack_to_stack(stacks->a, stacks->b);
	write(1, "pb\n", 3);
}
