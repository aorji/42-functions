/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:02:06 by aorji             #+#    #+#             */
/*   Updated: 2018/03/17 19:02:12 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_len(long a, long b)
{
	int i;

	i = -1;
	if (a < 0)
	{
		i++;
		a = -a;
	}
	while (++i, a)
		a /= b;
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	int			len;
	long		n;
	char		*str;
	
	if (base != 10 && value < 0)
		value = -value;
	len = ft_len(value, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (value < 0)
	{
		value = -value;
		str[0] = '-';
	}
	str[len] = '\0';
	len--;
	while (value >= base)
	{
		n = value;
		value /= base;
		n -= value * base;
		if (n >= 10 && n <= base)
			str[len] = n + 55;
		else
			str[len] = n + 48;
		len--;
	}
	if (value >= 10 && value < base)
		str[len] = (value + 55);
	if (value < 10)
		str[len] = value + 48;
	return (str);
}

int main()
{
	printf("%s\n", ft_itoa_base(-123, 16));
}