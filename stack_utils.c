/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:52:40 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 20:53:32 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *s, t_node *new)
{
	if (!new)
		return ;
	new->next = s->head;
	if (!s->head)
		s->tail = new;
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
	if (!s->head)
		s->tail = NULL;
	res->next = NULL;
	s->size--;
	return (res);
}

/* 
t_node	*find_last(t_stack *s)
{
	t_node	*res;

	if (!s || !s->head)
		return (NULL);
	res = s->head;
	while (res->next)
		res = res->next;
	return (res);
} */

void	unshift(t_stack *s, t_node *new)
{
	if (!s || !new)
		return ;
	if (!s->head)
		s->head = new;
	else
		s->tail->next = new;
	s->tail = new;
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
		s->tail = NULL;
		return (tmp);
	}
	while (tmp->next->next)
		tmp = tmp->next;
	res = tmp->next;
	tmp->next = NULL;
	s->tail = tmp;
	return (res);
}
