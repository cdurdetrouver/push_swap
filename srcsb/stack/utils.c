/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:36:51 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/17 15:38:49 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap_bonus.h"

int	is_sorted_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_stackadd_back(t_stack **stack, int nbr)
{
	t_stack	*new;
	t_stack	*last;

	if (stack == NULL)
		return ;
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new->nb = nbr;
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		last = ft_last(*stack);
		last->next = new;
	}
}

t_stack	*ft_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
