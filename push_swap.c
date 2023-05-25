/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:30:42 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 23:06:26 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_top_elem(t_push_swap *stacks)
{
	if (stacks->a->head->data > stacks->a->tail->data)
		ra(stacks);
	// TODO
}

void	sort_five(t_push_swap *stacks)
{
	pb(stacks);
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
	sort_top_elem(stacks);
	pa(stacks);
	sort_top_elem(stacks);
	// TODO
}

void	sort_push_swap(t_push_swap *stacks)
{
	if (stacks->a->size < 2)
		return ;
	else if (stacks->a->size < 3)
		sort_two(stacks);
	else if (stacks->a->size < 4)
		sort_three(stacks);
	else if (stacks->a->size < 6)
		sort_five(stacks);
}

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

int	main(int ac, char **av)
{
	t_push_swap	*info;

	info = create_push_swap();
	if (parse_input(ac, av, info))
	{
		ft_putstr_fd("Error\n", 2);
		delete_push_swap(&info);
		return (1);
	}
	print_push_swap(info);
	assign_ranks(info);
	print_push_swap(info);
	sort_push_swap(info);
	print_push_swap(info);
	delete_push_swap(&info);
	return (0);
}
