/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:28:04 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/16 17:16:40 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_push_swap.h"

int	error_repetition(t_stack *a, int nbr)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->nb == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	error_free(t_stack **a, char **split, int flag)
{
	free_stack(a);
	if (flag)
		free_split(split);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
