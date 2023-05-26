/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:30:42 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/26 17:44:43 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_shift_limit(int	num)
{
	int	i;

	i = 0;
	while (1 << i <= num)
		i++;
	return (i);
}

void	sift_by_nth_bit(t_push_swap *stacks, int shift)
{
	int		i;
	int		iterations;

	iterations = stacks->a->size;
	/* ft_putstr_fd("how many nodes to move: ", 1);
	ft_putnbr_fd(iterations, 1);
	ft_putstr_fd("\n", 1); */
	i = 0;
	while (i < iterations)
	{
		/* ft_putstr_fd("i: ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("(1 << shift): ", 1);
		ft_putnbr_fd(1 << shift, 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("condition: ", 1);
		ft_putnbr_fd(stacks->a->head->rank & (1 << shift), 1);
		ft_putstr_fd("\n", 1); */
		if (stacks->a->head->rank & (1 << shift))
			ra(stacks);
		else
			pb(stacks);
		i++;
	}
}

void	move_b_to_a_conditional(t_push_swap *stacks, int shift)
{
	int		i;
	int		iterations;

	iterations = stacks->b->size;
	i = 0;
	while (i < iterations)
	{
		if (stacks->b->head->rank & (1 << shift))
			pa(stacks);
		else
			rb(stacks);
		i++;
	}
}

void	move_b_to_a_full(t_push_swap *stacks)
{
	while (stacks->b->size)
		pa(stacks);
}

void	sort_large(t_push_swap *stacks)
{
	int	shift_limit;
	int	i;

	shift_limit = calculate_shift_limit(stacks->a->size);
/* 	ft_putnbr_fd(shift_limit, 1);
	ft_putstr_fd("\n", 1); */
	i = 0;
	while (i < shift_limit)
	{
		sift_by_nth_bit(stacks, i);
		if (i < shift_limit - 1)
			move_b_to_a_conditional(stacks, i + 1);
		else
			move_b_to_a_full(stacks);
		i++;
	}
}

void	sort_push_swap(t_push_swap *stacks)
{
	if (stacks->a->size < 2)
		return ;
	else if (stacks->a->size < 3)
		sort_two(stacks);
	else if (stacks->a->size < 4)
		sort_three(stacks);
	else if (stacks->a->size < 5)
		sort_four(stacks);
	else if (stacks->a->size < 6)
		sort_five(stacks);
	else
		sort_large(stacks);
}

int	is_sorted(t_push_swap	*stacks)
{
	int		min;
	t_node	*tmp;

	tmp = stacks->a->head;
	min = -1;
	while (tmp)
	{
		if (min > tmp->rank)
			return (0);
		min = tmp->rank;
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_push_swap	*stacks;

	stacks = create_push_swap();
	if (parse_input(ac, av, stacks))
	{
		ft_putstr_fd("Error\n", 2);
		delete_push_swap(&stacks);
		return (1);
	}
	assign_ranks(stacks);
	//print_push_swap(stacks);
	if (!is_sorted(stacks))
		sort_push_swap(stacks);
	//print_push_swap(stacks);
	delete_push_swap(&stacks);
	return (0);
}
