/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:18:07 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 15:25:33 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	push(s, shift(s));
}

void	rra(t_push_swap *stacks)
{
	reverse_rotate(stacks->a);
}

void	rrb(t_push_swap *stacks)
{
	reverse_rotate(stacks->b);
}

void	rrr(t_push_swap *stacks)
{
	reverse_rotate(stacks->a);
	reverse_rotate(stacks->b);
}
