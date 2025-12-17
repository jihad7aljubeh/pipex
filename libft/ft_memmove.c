/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:30:33 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/28 19:25:52 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned const char	*a;
	unsigned char		*b;

	a = (unsigned const char *)src;
	b = (unsigned char *)dest;
	i = 0;
	if (b > a)
	{
		while (n-- > 0)
		{
			b[n] = a[n];
		}
	}
	else
	{
		while (i < n)
		{
			b[i] = a[i];
			i++;
		}
	}
	return (b);
}
