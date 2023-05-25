/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:18:56 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 15:24:03 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack(t_stack *s)
{
	t_node	*tmp;

	while (s->head)
	{
		tmp = s->head;
		s->head = s->head->next;
		free(tmp);
	}
	s->size = 0;
}

void	delete_stack(t_stack **s)
{
	clean_stack(*s);
	free(*s);
	*s = NULL;
}

void	delete_push_swap(t_push_swap **stacks)
{
	delete_stack(&(*stacks)->a);
	delete_stack(&(*stacks)->b);
	free(*stacks);
	*stacks = NULL;
}
