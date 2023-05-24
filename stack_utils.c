/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:52:40 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/24 19:37:49 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_node  *create_elem(int data)
{
	t_node *res;

	res = malloc(sizeof(t_node));
	ft_putstr_fd("creating\n", 1);
	if (!res)
		return (NULL); // memory allocation error
	ft_putstr_fd("created\n", 1);
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

	ft_putstr_fd("create\n", 1);
	res = malloc(sizeof(t_push_swap));
	if (!res)
		return (NULL); // memory allocation error
	res->a = create_stack();
	res->b = create_stack();
	return (res);
}

void push(t_stack *s, int data)
{
	t_node	*tmp;
	
	ft_putstr_fd("push\n", 1);
	tmp = create_elem(data);
	ft_putstr_fd("pushsdsg\n", 1);
	if (!tmp)
		return; // memory allocation error
	ft_putstr_fd("tmp->next\n", 1);
	tmp->next = s->head;
	ft_putstr_fd("rthsrthsrth\n", 1);
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

	ft_putstr_fd("print\n", 1);
	tmp = s->head;
	
	while (tmp)
	{
		ft_putnbr_fd(tmp->data, 1);
		ft_putstr_fd("->", 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}
