/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:11:11 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/26 19:16:21 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_shift_limit(int num)
{
	int	i;

	i = 0;
	while (1 << i <= num)
		i++;
	return (i);
}

void	sift_by_nth_bit(t_push_swap *stacks, int shift)
{
	int		i;
	int		iterations;

	iterations = stacks->a->size;
	i = 0;
	while (i < iterations)
	{
		if (stacks->a->head->rank & (1 << shift))
			ra(stacks);
		else
			pb(stacks);
		i++;
	}
}

void	move_b_to_a_conditional(t_push_swap *stacks, int shift)
{
	int		i;
	int		iterations;

	iterations = stacks->b->size;
	i = 0;
	while (i < iterations)
	{
		if (stacks->b->head->rank & (1 << shift))
			pa(stacks);
		else
			rb(stacks);
		i++;
	}
}

void	move_b_to_a_full(t_push_swap *stacks)
{
	while (stacks->b->size)
		pa(stacks);
}

void	sort_large(t_push_swap *stacks)
{
	int	shift_limit;
	int	i;

	shift_limit = calculate_shift_limit(stacks->a->size);
	i = 0;
	while (i < shift_limit)
	{
		sift_by_nth_bit(stacks, i);
		if (i < shift_limit - 1)
			move_b_to_a_conditional(stacks, i + 1);
		else
			move_b_to_a_full(stacks);
		i++;
	}
}
