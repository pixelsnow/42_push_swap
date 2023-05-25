/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:52:40 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 15:26:07 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *s, t_node *new)
{
	if (!new)
		return ;
	new->next = s->head;
	s->head = new;
	s->size++;
}

t_node	*pop(t_stack *s)
{
	t_node	*res;

	if (!s || !s->head)
		return (NULL);
	res = s->head;
	s->head = s->head->next;
	res->next = NULL;
	s->size--;
	return (res);
}

t_node	*find_last(t_stack *s)
{
	t_node	*res;

	if (!s || !s->head)
		return (NULL);
	res = s->head;
	while (res->next)
		res = res->next;
	return (res);
}

void	push_to_last(t_stack *s, t_node *new)
{
	if (!s || !s->head || !new)
		return ;
	find_last(s)->next = new;
	s->size++;
}

t_node	*shift(t_stack *s)
{
	t_node	*tmp;
	t_node	*res;

	if (!s || !s->head)
		return (NULL);
	s->size--;
	tmp = s->head;
	if (s->size == 1)
	{
		s->head = NULL;
		return (tmp);
	}
	while (tmp->next->next)
		tmp = tmp->next;
	res = tmp->next;
	tmp->next = NULL;
	return (res);
}
