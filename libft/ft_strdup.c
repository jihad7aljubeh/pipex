/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:54:31 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/27 20:23:45 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	while (src[j] != '\0')
	{
		p[j] = src[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}
