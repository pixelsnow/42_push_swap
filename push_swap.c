/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:30:42 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 20:54:07 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_push_swap(t_push_swap *stacks)
{
	(void)stacks;
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
