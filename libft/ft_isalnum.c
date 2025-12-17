/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:18:00 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/09 18:45:09 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	char	a;

	a = (char)c;
	if ((((a <= '9') && (a >= '0'))) || (((((a <= 'z') && (a >= 'a'))
					|| ((a <= 'Z') && (a >= 'A'))))))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/* int main(void)
{
    printf("%d\n",ft_isalnum('a'));
    printf("%d\n",ft_isalnum('9'));
    printf("%d\n",ft_isalnum(9));
} */