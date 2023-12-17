/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:53:05 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/17 14:40:25 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ch;
	char	*copy;

	if (!s)
		return (0);
	copy = (char *)s;
	if (c == 0)
		return (copy + ft_strlen(copy));
	ch = NULL;
	while (*copy)
	{
		if (*copy == (char)c)
		{
			ch = copy;
			return (ch);
		}
		copy++;
	}
	return (ch);
}
