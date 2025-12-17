/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:48:25 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/18 17:41:21 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;
	size_t	sum;

	s = ft_strlen(src);
	d = ft_strlen(dest);
	i = 0;
	sum = 0;
	if (size > d)
	{
		sum = s + d;
	}
	else
	{
		sum = s + size;
	}
	while (src[i] != '\0' && size > (d + 1))
	{
		dest[d] = src[i];
		i++;
		d++;
	}
	dest[d] = '\0';
	return (sum);
}
