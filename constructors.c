/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:18:59 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 15:23:40 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_elem(int data)
{
	t_node	*res;

	res = malloc(sizeof(t_node));
	if (!res)
		return (NULL);
	res->next = NULL;
	res->rank = -1;
	res->data = data;
	return (res);
}

t_stack	*create_stack(void)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->head = NULL;
	res->size = 0;
	return (res);
}

t_push_swap	*create_push_swap(void)
{
	t_push_swap	*res;

	res = malloc(sizeof(t_push_swap));
	if (!res)
		return (NULL);
	res->a = create_stack();
	res->b = create_stack();
	return (res);
}
