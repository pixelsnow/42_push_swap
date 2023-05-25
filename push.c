/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:55:31 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 15:24:36 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_from_stack_to_stack(t_stack *from, t_stack *to)
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
}

void	pb(t_push_swap *stacks)
{
	move_from_stack_to_stack(stacks->a, stacks->b);
}
