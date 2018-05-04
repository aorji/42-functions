/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:57:02 by aorji             #+#    #+#             */
/*   Updated: 2018/03/16 16:17:52 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int brainfuck(char *param, int *str)
{
	int i;
	int j;

	i = -1;
	while (++i, param[i])
	{
		if (param[i] == '+')
			++(*str);
		else if (param[i] == '-')
			--(*str);
		else if (param[i] == '>')
			++str;
		else if (param[i] == '<')
			--str;
		else if (param[i] == '.')
			write(1, str, 1);
		else if (param[i] == '[' && !(*str))
		{
			j = 1;
			while (j && param[i])
			{
				i++;
				if (param[i] == ']')
					j--;
				if (param[i] == '[')
					j++;
			}
		}
		else if (param[i] == ']' && *str)
		{
			j = 1;
			while (j && i > 0)
			{
				i--;
				if (param[i] == '[')
					j--;
				if (param[i] == ']')
					j++;
			}
		}
				
	}
	return (1);
}

int main(int ac, char **av)
{
	int str[1024] = {0};
	
	if (ac == 2)
		return(brainfuck(av[1], str));
}
