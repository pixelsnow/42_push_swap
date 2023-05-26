/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:41:21 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/26 19:15:37 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_min(t_push_swap *stacks, int i)
{
	t_node	*min;
	t_node	*tmp;

	tmp = stacks->a->head;
	min = NULL;
	while (tmp)
	{
		if (tmp->rank == -1 && (!min || tmp->data < min->data))
				min = tmp;
		tmp = tmp->next;
	}
	min->rank = i;
}

void	assign_ranks(t_push_swap *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a->size)
	{
		rank_min(stacks, i);
		i++;
	}
}
