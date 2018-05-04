/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:17:34 by aorji             #+#    #+#             */
/*   Updated: 2018/01/29 16:17:37 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int ft_pow(int a, int p)
{
	int res;
	res = 1;

	while (p)
	{
		res *= a;
		p--;
	}
	return(res);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int minus;
	int p;
	int res;

	i = 0;
	res = 0;
	p = 0;
	minus = 1;

	if (str_base < 2 && str_base > 16)
		return (0);
	if (str[0] == '-')
		minus = -1;
	while (str[i])
		i++;
	while (--i > 0)
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			res  += (str[i] - 87) * ft_pow(str_base, p);
		else if (str[i] >= 'A' && str[i] <= 'F')
			res  += (str[i] - 45) * ft_pow(str_base, p);
		else if (str[i] >= '0' && str[i] <= '9')
			res  += (str[i] - 48) * ft_pow(str_base, p);
		if (str[i] == '-')
			p--;
		p++;
	}
	if (minus == 1)
		res  += (str[i] - 48) * ft_pow(str_base, p);
	return (res * minus);
}

int main()
{
	printf("%d\n", ft_atoi_base("1110110001", 2));
}
