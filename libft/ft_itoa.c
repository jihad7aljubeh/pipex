/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:01:05 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/27 20:25:42 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	checknegative(int num1)
{
	int	flag;

	flag = 0;
	if (num1 < 0)
	{
		flag = 1;
	}
	return (flag);
}

int	countdigits(int num2)
{
	int	count;

	count = 1;
	if (checknegative(num2))
	{
		num2 = num2 * -1;
		count++;
	}
	while (num2 >= 10)
	{
		count++;
		num2 = num2 / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			mod;
	char		*str;
	int			digits;

	digits = countdigits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(digits + 1);
	if (!str)
		return (NULL);
	if (checknegative(n))
	{
		n = n * -1;
		str[0] = '-';
	}
	str[digits] = '\0';
	while ((digits - 1 >= 0) && (str[digits - 1] != '-'))
	{
		mod = n % 10;
		n = n / 10;
		str[digits - 1] = mod + '0';
		digits--;
	}
	return (str);
}
/*int main()
{
	printf("%s",ft_itoa(-123));
	return (0);
}*/