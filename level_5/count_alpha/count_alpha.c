/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:14:32 by exam              #+#    #+#             */
/*   Updated: 2018/04/13 15:25:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int al(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

void cast(char **st)
{
	char *s = *st;
	int i = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
		   s[i] = s[i] + 32;
		i++;
	}
}

void ca(char *s)
{
	int res[26] = {0};
	int i = 0;
	int j = 0;
	cast(&s);
	while (s[i])
	{
		if (al(s[i]))
			res[s[i] - 97]++;
		i++;
	}
	i = 0;
	while (s[i])
	{

		if (al(s[i]) && res[s[i] - 97])
		{
			j++ ? printf(", ") : 0;
			printf("%d%c", res[s[i] - 97], s[i]);
			res[s[i] - 97] = 0;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		ca(av[1]);
	printf("\n");
	return (0);
}

