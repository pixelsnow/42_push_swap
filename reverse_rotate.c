/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:18:07 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 15:42:41 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	push(s, shift(s));
}

void	rra(t_push_swap *stacks)
{
	reverse_rotate(stacks->a);
	write(1, "rra\n", 4);
}

void	rrb(t_push_swap *stacks)
{
	reverse_rotate(stacks->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_push_swap *stacks)
{
	reverse_rotate(stacks->a);
	reverse_rotate(stacks->b);
	write(1, "rrr\n", 4);
}
