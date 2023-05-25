/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:21:04 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 23:11:10 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_stack *s)
{
	t_node	*tmp;

	tmp = s->head;
	ft_putstr_fd("[", 1);
	ft_putnbr_fd(s->size, 1);
	ft_putstr_fd("]	", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->data, 1);
		ft_putstr_fd("(", 1);
		ft_putnbr_fd(tmp->rank, 1);
		ft_putstr_fd(")", 1);
		ft_putstr_fd(" -> ", 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 1);
}

void	print_push_swap(t_push_swap *stacks)
{
	ft_putstr_fd("A: ", 1);
	print_stack(stacks->a);
	ft_putstr_fd("B: ", 1);
	print_stack(stacks->b);
}
