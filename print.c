/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:21:04 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 15:24:20 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s)
{
	t_node	*tmp;

	tmp = s->head;
	ft_putstr_fd("size = ", 1);
	ft_putnbr_fd(s->size, 1);
	ft_putstr_fd("	", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->data, 1);
		ft_putstr_fd(" -> ", 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 1);
}
