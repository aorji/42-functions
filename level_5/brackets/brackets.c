/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:20:15 by exam              #+#    #+#             */
/*   Updated: 2018/03/27 11:50:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int next(char *s, char c)
{
	int i;
	int b;

	b = 1; 
	i = 1;
	while (i && *(++s) && b)
	{
		if (*s == c || *s == c + (c % 2) + 1)
			(*s == c) ? b++ : b--;
		i++;
	}
	return (i);
}

int ft_br(char *s, char c)
{
	if (*s == c)
		return (1);
	else if (*s == ')' || *s == '}' || *s == ']' || *s == '\0')
		return (0);
	else if (*s == '(' || *s == '{' || *s == '[')
		return (ft_br(s + 1, *s + (*s % 2) + 1) * ft_br(s + next(s, *s), c));
	else 
		return (ft_br(s + 1, c));
}

int main(int ac, char **av)
{
	int i;
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			ft_br(av[i], 0) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
