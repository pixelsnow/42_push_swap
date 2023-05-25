/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:58:44 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 15:26:27 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
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
}

void	sb(t_push_swap *stacks)
{
	swap(stacks->b);
}

void	ss(t_push_swap *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
}
