/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:43:54 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/17 02:42:44 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void	cost_b(t_stack *a, t_stack *b)
{
	t_stack		*target;
	t_stack		*current_a;
	long int	best;

	while (b)
	{
		best = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nb < best && current_a->nb > b->nb)
			{
				best = current_a->nb;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best == LONG_MAX)
			b->closest = ft_lowest(a);
		else
			b->closest = target;
		b = b->next;
	}
}

void	b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*target;

	set_index(a);
	set_index(b);
	cost_b(*a, *b);
	target = (*b)->closest;
	node_to_topa(a, target);
	pa(a, b);
}
