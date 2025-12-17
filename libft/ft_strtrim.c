/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:09:53 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/27 16:28:38 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (s1[x] && ft_strchr(set, s1[x]))
		x++;
	while (s1[y] && ft_strchr(set, s1[y]))
		y--;
	return (ft_substr(s1, x, y - x + 1));
}
/*int main()
{
	printf("%s" ,
			ft_strtrim("acbcbabcabcbabcabcb  abacabacbacbacbcabc" ,"abc ")); 
	return (0);
}*/