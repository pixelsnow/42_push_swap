/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:30:42 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/26 19:11:45 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_push_swap(t_push_swap *stacks)
{
	if (stacks->a->size < 2)
		return ;
	else if (stacks->a->size < 3)
		sort_two(stacks);
	else if (stacks->a->size < 4)
		sort_three(stacks);
	else if (stacks->a->size < 5)
		sort_four(stacks);
	else if (stacks->a->size < 6)
		sort_five(stacks);
	else
		sort_large(stacks);
}

static int	is_sorted(t_push_swap	*stacks)
{
	int		min;
	t_node	*tmp;

	tmp = stacks->a->head;
	min = -1;
	while (tmp)
	{
		if (min > tmp->rank)
			return (0);
		min = tmp->rank;
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_push_swap	*stacks;

	stacks = create_push_swap();
	if (parse_input(ac, av, stacks))
	{
		ft_putstr_fd("Error\n", 2);
		delete_push_swap(&stacks);
		return (1);
	}
	assign_ranks(stacks);
	if (!is_sorted(stacks))
		sort_push_swap(stacks);
	delete_push_swap(&stacks);
	return (0);
}
