/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:02:00 by aorji             #+#    #+#             */
/*   Updated: 2018/01/29 13:02:01 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void put_nbr(int nb)
{
	long int numb;
	char res;

	numb = nb;
	if (numb > 9)
	{
		put_nbr(numb / 10);
		put_nbr(numb % 10);
	}
	else
	{
		res = numb + 48;
		write(1, &res, 1);
	}
}

int ft_atoi(char *str)
{
	int i;
	int m;
	int res;

	m = 1;
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{	
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return(res * m);
}

int is_prime(int i)
{
	int j;

	j = 2;
	while (j <= (i / 2))
	{
		if (!(i % j))
			return (0);
		j++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int a;
	int i;
	int res;

	i = 2;
	res = 0;
	if (argc != 2 || (a = ft_atoi(argv[1])) < 0)
	{
		put_nbr(0);
		write(1, "\n", 1);
		return (0);
	}
	while (i <= a)
	{
		if (is_prime(i))
			res += i;
		i++;
	}
	put_nbr(res);
	write(1, "\n", 1);
	return (0);
}