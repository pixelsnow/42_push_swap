/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:52:40 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/22 19:03:25 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_node  *create_elem(int data)
{
	t_node *res;

	res = malloc(sizeof(t_node));
	if (res)
	{
		res->next = NULL;
		res->data = data;
	}
	else
		return (NULL);
	return (res);
}

t_stack	*create_stack(void)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (res)
	{
		res->head = NULL;
	}
	return (res);
}

/* 
void push(t_stack *s, int data)
{
	t_node	*tmp;
	
	tmp = create_elem(data);
	tmp->next = s->head;
	s->head = tmp;
	if (!s->head)
	{
		s->head = tmp;
	}
	else
	{
		
		q->last = tmp;
	}
}

void de_queue(t_stack *q)
{
	t_node *tmp;
	
	if (!q->head)
		return ;
	tmp = q->head;
	q->head = q->head->next;
	if (tmp->data)
		free(tmp->data);
	free(tmp);
}

void clean_queue(t_stack *q)
{
	while (q->head)
		de_queue(q);
}

void delete_queue(t_stack **s)
{
	free(*s);
	s = NULL;
}
 */

void print_stack(t_stack *s)
{
	t_node *tmp;

	tmp = s->head;
	while (tmp)
	{
		ft_putstr(tmp->data);
		ft_putstr("->");
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
