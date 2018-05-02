/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:13:05 by exam              #+#    #+#             */
/*   Updated: 2018/01/26 15:22:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;
	int k;

	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 0;
	k = 0;
	while (argv[1][k])
		k++;
	while (argv[1][i] && argv[2][j])
	{
		if (argv[2][j] != argv[1][i])
			j++;
		else
			i++;
	}
	if (k == i)
	{
		i = 0;
		while (argv[1][i])
		{
			write(1, &argv[1][i], 1); 
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
