/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:12:06 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/17 15:14:31 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	size_t			i;

	if (nmemb == 0 || size == 0 || __SIZE_MAX__ / nmemb < size)
		return (NULL);
	i = 0;
	tab = malloc(size * nmemb);
	if (!tab)
		return (0);
	while (i < size * nmemb)
		tab[i++] = 0;
	return (tab);
}
