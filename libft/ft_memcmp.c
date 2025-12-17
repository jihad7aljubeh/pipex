/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:14:02 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/28 19:27:14 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n)
	{
		if (a[i] != b[i])
			return ((int)(a[i] - b[i]));
		i++;
	}
	if (i == n)
		return ((int)(a[i - 1] - b[i - 1]));
	return ((int)(a[i] - b[i]));
}
