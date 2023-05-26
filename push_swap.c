/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:30:42 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/26 14:43:00 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large(t_push_swap *stacks)
{
	(void) stacks;
}

void	sort_push_swap(t_push_swap *stacks)
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
