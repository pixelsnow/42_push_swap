/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:52:40 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/24 19:23:10 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_node  *create_elem(int data)
{
	t_node *res;

	res = malloc(sizeof(t_node));
	if (!res)
		return (NULL); // memory allocation error
	res->next = NULL;
	res->data = data;
	return (res);
}

t_stack	*create_stack(void)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL); // memory allocation error
	res->head = NULL;
	return (res);
}

t_push_swap	*create_push_swap(void)
{
	t_push_swap	*res;

	res = malloc(sizeof(t_push_swap));
	if (!res)
		return (NULL); // memory allocation error
	res->a = NULL;
	res->b = NULL;
	return (res);
}

void push(t_stack *s, int data)
{
	t_node	*tmp;
	
	tmp = create_elem(data);
	if (!tmp)
		return; // memory allocation error
	tmp->next = s->head;
	s->head = tmp;
}

t_node *pop(t_stack *s)
{
	t_node	*res;

	if (!s || !s->head)
		return (NULL);
	res = s->head;
	res->next = NULL;
	s->head = s->head->next;
	return (res);
}

void	clean_stack(t_stack *s)
{
	t_node	*tmp;
	
	while (s->head)
	{
		tmp = s->head;
		s->head = s->head->next;
		free(tmp);
	}
}


void	delete_stack(t_stack **s)
{
	clean_stack(*s);
	free(*s);
	s = NULL;
}


void	print_stack(t_stack *s)
{
	t_node *tmp;

	tmp = s->head;
	ft_putstr_fd("hi", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->data, 1);
		ft_putstr_fd("->", 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}
