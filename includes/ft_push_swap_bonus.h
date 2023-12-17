/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:50:35 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/17 15:58:39 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_BONUS_H
# define FT_PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				cost;
	int				nb;
	int				index;
	bool			cheap;
	bool			sup_moyenne;
	struct s_stack	*next;
	struct s_stack	*closest;
}					t_stack;

// ACTION
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// UTILS
void				read_instructions(t_stack **stack_a, t_stack **stack_b);
char				**ft_split_argv(const char *str, char charset);
int					is_sorted_stack(t_stack **stack);
void				ft_stackadd_back(t_stack **stack, int nbr);

// ERROR
int					error_repetition(t_stack *a, int nbr);
void				error_free(t_stack **a, char **split, int flag);
t_stack				*ft_last(t_stack *stack);
void				print_error(void);

// FREE
void				free_stack(t_stack **stack);
void				free_split(char **split);

// CHECK
void				ft_check(t_stack **stack_a, t_stack **stack_b, char *line);

#endif
