/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:25:12 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/24 22:01:17 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	push_to_last(s, pop(s));
}

void ra(t_push_swap *stacks)
{
	rotate(stacks->a);
}

void rb(t_push_swap *stacks)
{
	rotate(stacks->b);
}

void rr(t_push_swap *stacks)
{
	rotate(stacks->a);
	rotate(stacks->b);
}