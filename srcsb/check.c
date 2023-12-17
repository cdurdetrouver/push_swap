/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:26:42 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/17 16:36:12 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap_bonus.h"

char	*ft_sub_check(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0 && line[3] == '\0')
		sa(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0 && line[3] == '\0')
		sb(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0 && line[3] == '\0')
		ss(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0 && line[3] == '\0')
		pa(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0 && line[3] == '\0')
		pb(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0 && line[3] == '\0')
		ra(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0 && line[3] == '\0')
		rb(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0 && line[3] == '\0')
		rr(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0 && line[4] == '\0')
		rra(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0 && line[4] == '\0')
		rrb(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0 && line[4] == '\0')
		rrr(a, b);
	else
		print_error();
	return (get_next_line(0));
}

void	ft_check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*tmp;

	while (line)
	{
		tmp = line;
		line = ft_sub_check(line, stack_a, stack_b);
		free(tmp);
	}
	if (*stack_b && !is_sorted_stack(stack_a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	free(line);
}
