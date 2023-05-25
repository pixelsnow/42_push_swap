/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:47:21 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 22:10:26 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_split(char	**splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

static long long	ft_simple_atoi(const char *str)
{
	char		sign;
	long long	res;

	sign = 1;
	res = 0;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*(str++) - '0');
	return (res * sign);
}

int	check_repeats(t_push_swap *stacks, int num)
{
	t_node	*tmp;

	tmp = stacks->a->head;
	while (tmp)
	{
		if (tmp->data == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	parse_item(const char *item, t_push_swap *stacks)
{
	int			i;
	long long	num;

	i = 0;
	if (item[i] == '-' || item[i] == '+')
		i++; // Sign in the beginning is acceptable
	if (!item[i] || ft_strlen(item) > 11)
		return (1); // if there's nothing after the sign or it's too long, abort
	while (item[i])
	{
		if (!ft_isdigit(item[i]))
			return (1); // If there's any non-digits, abort
		i++;
	}
	num = ft_simple_atoi(item);
	if (num < INT_MIN || num > INT_MAX || check_repeats(stacks, (int)num))
		return (1); // If it's out of int range or there is repeats, abort
	unshift(stacks->a, create_elem((int)num));
	return (0);
}

int	parse_input(int ac, char **av, t_push_swap *stacks)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (i < ac) // Looping through input arguments 
	{
		split = ft_split(av[i], ' '); // Creating a split
		if (!split || !split[0])
			return (1);
		j = 0;
		while (split[j]) // Looping through split strings
		{
			if (parse_item(split[j], stacks)) // If faulty arg is found, abort
			{
				delete_split(split);
				return (1);
			}
			j++;
		}
		delete_split(split); // Free split after parsing every arg
		i++;
	}
	return (0);
}
