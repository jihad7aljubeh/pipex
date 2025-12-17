/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:21:23 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/18 22:52:34 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*a;
	char		*b;

	b = (char *)dest;
	a = (const char *)src;
	i = 0;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dest);
}
