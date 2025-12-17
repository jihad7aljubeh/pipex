/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:40:17 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/27 20:23:32 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*a;

	if (nmemb == 0 || size == 0)
	{
		a = (char *)malloc(1);
		if (!a)
			return (NULL);
		return (a);
	}
	a = (char *)malloc(size * nmemb);
	if (!a)
		return (NULL);
	ft_bzero(a, nmemb * size);
	return ((void *)a);
}
