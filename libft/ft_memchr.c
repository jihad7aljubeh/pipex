/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:29:38 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/27 20:23:02 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;
	size_t				i;

	i = 0;
	a = (const unsigned char *)s;
	while (i < n)
	{
		if (a[i] == (unsigned char)c)
		{
			return ((void *)(a + i));
		}
		i++;
	}
	return (NULL);
}
