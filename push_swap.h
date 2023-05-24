/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:12 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/24 19:20:30 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	struct s_node	*next;
	int				rank;
	int				data;
}					t_node;

typedef struct s_stack
{
	struct s_node	*head;
	int				size;
}					t_stack;

typedef struct s_push_swap
{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_push_swap;

t_stack	*create_stack(void);
t_push_swap	*create_push_swap(void);
void 	push(t_stack *s, int data);
void	delete_stack(t_stack **s);
void	print_stack(t_stack *s);

void	sa(t_push_swap *stacks);
void	sb(t_push_swap *stacks);
void	ss(t_push_swap *stacks);

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

#endif
