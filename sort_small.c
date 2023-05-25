/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:12:42 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 22:14:07 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_semantic(t_push_swap *stacks, int first, int second, int third)
{
	if (first > second)
	{
		if (second > third)
		{
			sa(stacks);
			rra(stacks);
		}
		else
		{
			if (first > third)
				ra(stacks);
			else
				sa(stacks);
		}
	}
	else if (second > third)
	{
		if (first > third)
			rra(stacks);
		else
		{
			sa(stacks);
			ra(stacks);
		}
	}
}

void	sort_three(t_push_swap *stacks)
{
	sort_semantic(stacks, stacks->a->head->data,
		stacks->a->head->next->data, stacks->a->head->next->next->data);
}

void	sort_two(t_push_swap *stacks)
{
	if (stacks->a->head->data > stacks->a->tail->data)
		sa(stacks);
}
