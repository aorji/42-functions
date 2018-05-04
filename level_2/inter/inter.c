/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:58:22 by aorji             #+#    #+#             */
/*   Updated: 2018/01/28 19:58:25 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int ft_self(char *str, char c, int j)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while(str[i])
	{
		
		if (str[i] == c && i < j)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i;
	int j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 0;
	while(argv[1][i] && argv[2][j])
	{
		if (argv[1][i] == argv[2][j])
		{
			if (ft_self(argv[1], argv[1][i], i))
				write(1, &argv[1][i], 1);
			i++;
			j = 0;
		}
		else
		{
			j++;
			if (argv[2][j] == '\0')
			{
				i++;
				j = 0;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}