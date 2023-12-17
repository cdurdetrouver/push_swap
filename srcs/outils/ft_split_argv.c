/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:42:29 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/12 17:09:41 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

static char	**allocate_dest(int word_count)
{
	char	**dest;

	dest = malloc((word_count + 2) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest[0] = ft_strdup("./push_swap");
	return (dest);
}

static void	fill_dest(const char *str, char charset, char **dest,
		int word_count)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	k = 1;
	while (k < (word_count + 1))
	{
		while (str[i] == charset)
			i++;
		len = ft_next_sep(i, str, charset);
		dest[k] = str_copy(i, len, str);
		if (!dest[k])
		{
			clean(dest, k);
			return ;
		}
		i += len;
		k++;
	}
	dest[k] = NULL;
}

char	**ft_split_argv(const char *str, char charset)
{
	int		word_count;
	char	**dest;

	word_count = count_words(str, charset);
	dest = allocate_dest(word_count);
	if (!dest)
		return (NULL);
	fill_dest(str, charset, dest, word_count);
	return (dest);
}
