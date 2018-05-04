/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:12:27 by aorji             #+#    #+#             */
/*   Updated: 2018/04/16 16:12:28 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int len(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

int is_op(char *s)
{
	if (*s == 43 || *s == 42 || *s == 45 || *s == 47 || *s == 37)
		return (1);
	return (0);
}

int wc(char *s)
{
	int i = 0;

	while (s[i] == ' ' && s[i])
		i++;
	return (i);
}

int len_d(long i)
{
	int len = 0;
	
	if (i < 0)
	{
		i = -i;
		len++;
	}
	else if (i == 0)
		return (1);
	while (i)
	{
		i /= 10;
		len++;
	}
	return (len);
}

void calc(int **t, char c, int *j)
{
	int i = *j - 1;

	*j = i;
	if (i < 1)
	{
		printf("Error\n");
		exit (1);
	}
	if (c == 42)
		(*t)[i - 1] = (*t)[i] * (*t)[i - 1];
	if (c == 43)
		(*t)[i - 1] = (*t)[i] + (*t)[i - 1];
	if (c == 45)
		(*t)[i - 1] = (*t)[i - 1] - (*t)[i];
	if (c == 47)
		(*t)[i - 1] = (*t)[i - 1] / (*t)[i];
	if (c == 37)
		(*t)[i - 1] = (*t)[i - 1] % (*t)[i];
}

int rpn(char *s, int *err)
{
	int *tab;
	int l;
	int j = 0;

	l = len(s);
	tab = (int *)malloc(sizeof(int) * l);
	while (*s)
	{
		if (!is_op(s))
		{
			tab[j] = atoi(s);
			s += len_d(tab[j++]);
			s += wc(s);
		}
		if (is_op(s))
		{	
			calc(&tab, *s, &j);
			s++;
			s += wc(s);
		}
	}
	if (j != 1)
		*err = 1;
	return(tab[0]);
}

int main(int ac, char **av)
{
	int err = 0;
	int res;

	if (ac == 2)
		res = rpn(av[1], &err);
	if (ac != 2 || err)
	{
		printf("Error\n");
		return (0);
	}
	printf("%d\n", res);
	return (0);
}
