/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:08:30 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/16 14:25:28 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_push_swap.h"

static void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
