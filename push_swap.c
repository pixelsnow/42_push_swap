/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:30:42 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 21:56:19 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_semantic(t_push_swap *stacks, int first, int second, int third)
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
	sort_three_semantic(stacks, stacks->a->head->data,
		stacks->a->head->next->data, stacks->a->head->next->next->data);
}

void	sort_two(t_push_swap *stacks)
{
	if (stacks->a->head->data > stacks->a->tail->data)
		sa(stacks);
}

void	sort_push_swap(t_push_swap *stacks)
{
	if (stacks->a->size < 2)
		return;
	else if (stacks->a->size < 3)
		sort_two(stacks);
	else if (stacks->a->size < 4)
		sort_three(stacks);
}

int	main(int ac, char **av)
{
	t_push_swap	*info;
	int			input_status;

	info = create_push_swap();
	input_status = parse_input(ac, av, info);
	if (input_status == 1)
	{
		ft_putstr_fd("Error\n", 2);
		delete_push_swap(&info);
		return (1);
	}
	print_push_swap(info);
	sort_push_swap(info);
	print_push_swap(info);
	delete_push_swap(&info);
	return (0);
}
