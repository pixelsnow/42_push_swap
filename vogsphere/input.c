/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:47:21 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/26 20:09:28 by vvagapov         ###   ########.fr       */
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
		i++;
	if (!item[i] || ft_strlen(item) > 11 || (item[i] == '0' && item[i + 1]))
		return (1);
	while (item[i])
	{
		if (!ft_isdigit(item[i]))
			return (1);
		i++;
	}
	num = ft_simple_atoi(item);
	if (num < INT_MIN || num > INT_MAX || check_repeats(stacks, (int)num))
		return (1);
	unshift(stacks->a, create_elem((int)num));
	return (0);
}

int	parse_input(int ac, char **av, t_push_swap *stacks)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split || !split[0])
		{
			delete_split(split);
			return (1);
		}
		j = 0;
		while (split[j])
		{
			if (parse_item(split[j], stacks))
				return (delete_split(split), 1);
			j++;
		}
		delete_split(split);
		i++;
	}
	return (0);
}
