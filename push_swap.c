/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:30:42 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 15:47:58 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input(int ac, char **av)
{
	(void) ac;
	(void) av;
	return (0);
}

int	main(int ac, char **av)
{
	t_push_swap	*info;

	if (ac < 2)
		return (0);
	if (validate_input(ac, av))
		return (0);
	info = create_push_swap();
	push(info->a, create_elem(1));
	delete_push_swap(&info);
	return (0);
}
