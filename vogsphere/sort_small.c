/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:41:54 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/26 19:17:10 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_mins(t_push_swap *stacks, int	*min1, int	*min2)
{
	t_node	*tmp;

	*min1 = 5;
	*min2 = 5;
	tmp = stacks->a->head;
	while (tmp)
	{
		if (tmp->rank < *min1)
		{
			*min2 = *min1;
			*min1 = tmp->rank;
		}
		else if (tmp->rank < *min2)
		{
			*min2 = tmp->rank;
		}
		tmp = tmp->next;
	}
}

static void	extract_mins(t_push_swap *stacks)
{
	int		min1;
	int		min2;

	find_mins(stacks, &min1, &min2);
	while (stacks->a->head->rank != min1 && stacks->a->head->rank != min2)
		ra(stacks);
	pb(stacks);
	while (stacks->a->head->rank != min1 && stacks->a->head->rank != min2)
		ra(stacks);
	pb(stacks);
	if (stacks->b->head->rank < stacks->b->head->next->rank)
		rb(stacks);
}

void	sort_four(t_push_swap *stacks)
{
	int		min1;
	int		min2;

	find_mins(stacks, &min1, &min2);
	while (stacks->a->head->rank != min1)
		ra(stacks);
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}

void	sort_five(t_push_swap *stacks)
{
	extract_mins(stacks);
	sort_three(stacks);
	pa(stacks);
	pa(stacks);
}
