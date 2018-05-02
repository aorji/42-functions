/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:07:47 by exam              #+#    #+#             */
/*   Updated: 2018/01/26 16:17:54 by exam             ###   ########.fr       */
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

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc == 1)
	{
		write(1, "0", 1);
		write(1, "\n", 1);
		return (0);
	}

	while (argv[i])
	{
		i++;
		j++;
	}
	putnbr(j);
	write(1, "\n", 1);
	return (0);
}
