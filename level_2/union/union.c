/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:03:40 by aorji             #+#    #+#             */
/*   Updated: 2018/01/29 12:03:41 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_self(char *str, char c, int i)
{
	int j;

	j = 0;
	while(str[j])
	{
		if (str[j] == c && j < i)
			return (0);
		j++;
	}
	return (1);
}

int ft_find(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			i++;
		else
			return (1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (ft_self(argv[1], argv[1][i], i))
			write(1, &argv[1][i], 1);
		i++;
	}
	while(argv[2][j])
	{
		if (!ft_find(argv[1], argv[2][j]) && ft_self(argv[2], argv[2][j], j))
			write(1, &argv[2][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return 0;
}