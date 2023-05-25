/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:58:44 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 15:43:19 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
}

void	sa(t_push_swap *stacks)
{
	swap(stacks->a);
	write(1, "sa\n", 3);
}

void	sb(t_push_swap *stacks)
{
	swap(stacks->b);
	write(1, "sb\n", 3);
}

void	ss(t_push_swap *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
	write(1, "ss\n", 3);
}
