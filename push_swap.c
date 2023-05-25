/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:30:42 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/25 20:37:13 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_split(char	**splits)
{
	int i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

long long ft_simple_atoi(const char *str)
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

int parse_item(const char *item, t_push_swap *stacks)
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
			return (1); // If there is any non-digits, abort
		i++;
	}
	// Everything is OK, parse and add to the end of A stack
	num = ft_simple_atoi(item);
	if (num < INT_MIN || num > INT_MAX)
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
	while (i < ac) // Looping through input arguments 
	{
		split = ft_split(av[i], ' '); // Creating a split
		if (!split)
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

int	main(int ac, char **av)
{
	t_push_swap	*info;
	int			input_status;
	
	info = create_push_swap();
	input_status = parse_input(ac, av, info);
	if (input_status == 1)
	{
		ft_putstr_fd("Error\n", 2);
		delete_push_swap(&info);
		return (1);
	}
	print_push_swap(info);
	delete_push_swap(&info);
	return (0);
}
