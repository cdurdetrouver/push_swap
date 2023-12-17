/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:41:32 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/17 15:40:08 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap_bonus.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*new_last;

	if (!*stack || !(*stack)->next)
		return ;
	current = *stack;
	while (current->next->next)
		current = current->next;
	new_last = current->next;
	current->next = NULL;
	new_last->next = *stack;
	*stack = new_last;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
