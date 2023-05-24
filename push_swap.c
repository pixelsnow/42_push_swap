/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:30:42 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/24 22:16:50 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_push_swap	*info;
	
	info = create_push_swap();
	push(info->a, create_elem(1));
	push(info->a, create_elem(2));
	push(info->a, create_elem(3));
	push(info->a, create_elem(4));
 	print_stack(info->a);
	ra(info);
	print_stack(info->a);
	rra(info);
	print_stack(info->a);
	delete_push_swap(&info);
	return (0);
}
