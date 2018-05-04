/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:55:27 by aorji             #+#    #+#             */
/*   Updated: 2018/01/29 14:55:29 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_len(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int num_w(char* str)
{
	int i;
	int w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1]))
			w++;
		i++;
	}
	return (w);
}


int main(int argc, char *argv[])
{
	int len;
	int i;
	int w;

	i = 0;
	if (argc != 2 || !(len = ft_len(argv[1])))
	{
		write(1, "\n", 1);
		return (0);
	}
	w = num_w(argv[1]);
	while (len)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
		{
			i++;
			len--;
		}
		while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
			len--;
		}
		if (w - 1)
		{
			write(1, " ", 1);
			w--;
		}
		
	}
	write(1, "\n", 1);
	return 0;
}