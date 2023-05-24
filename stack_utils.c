/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:52:40 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/24 21:15:34 by vvagapov         ###   ########.fr       */
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
	res->rank = -1;
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
	res->size = 0;
	return (res);
}

t_push_swap	*create_push_swap(void)
{
	t_push_swap	*res;

	res = malloc(sizeof(t_push_swap));
	if (!res)
		return (NULL); // memory allocation error
	res->a = create_stack();
	res->b = create_stack();
	return (res);
}

void push(t_stack *s, t_node *new)
{
	if (!new)
		return; // memory allocation error
	new->next = s->head;
	s->head = new;
	s->size++;
}

t_node *pop(t_stack *s)
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

void	clean_stack(t_stack *s)
{
	t_node	*tmp;
	
	while (s->head)
	{
		tmp = s->head;
		s->head = s->head->next;
		free(tmp);
	}
	s->size = 0;
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
	ft_putstr_fd("size = ", 1);
	ft_putnbr_fd(s->size, 1);
	ft_putstr_fd("	", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->data, 1);
		ft_putstr_fd(" -> ", 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 1);
}
