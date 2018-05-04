/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.print_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:37:00 by aorji             #+#    #+#             */
/*   Updated: 2018/01/29 17:37:04 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putnbr(int j)
{
	int nb;

	if (j > 9)
	{
		putnbr(j/10);
		putnbr(j%10);
	}
	else
	{
		nb = j + 48;
		write(1, &nb, 1);
	}

}

int	ft_atoi(const char *str)
{
	int i;
	long int res;
	int minus;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;

	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res * minus);
}

void print_hex(int n)
{
	int a;

	if (n > 15)
	{
		print_hex(n / 16);
		print_hex(n % 16);
	}
	if (n >= 10 && n <= 15)
	{
		a = n + 87; 
		write(1, &a, 1);
	}
	if (n < 10)
		putnbr(n);
}

int main(int argc, char *argv[])
{
	int a;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return 0;
}
