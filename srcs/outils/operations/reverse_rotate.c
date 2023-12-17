/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:41:32 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/16 17:32:54 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_push_swap.h"

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
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
