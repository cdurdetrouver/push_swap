/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:17:48 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/18 15:43:58 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_arg_to_stack(t_stack **stack, char **argv, int flag)
{
	long	nbr;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isnumeric(argv[i]))
			error_free(stack, argv, flag);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(stack, argv, flag);
		if (error_repetition(*stack, (int)nbr))
			error_free(stack, argv, flag);
		ft_stackadd_back(stack, (int)nbr);
		++i;
	}
	if (flag)
		free_split(argv);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error\n"), 1);
	else if (argc == 2)
		argv = ft_split_argv(argv[1], ' ');
	ft_arg_to_stack(&stack_a, argv, argc == 2);
	stack_b = NULL;
	if (!is_sorted_stack(&stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
