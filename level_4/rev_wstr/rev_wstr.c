/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:13:19 by aorji             #+#    #+#             */
/*   Updated: 2018/02/01 19:13:20 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int count_w(char *str)
{
	int i;
	int w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n' || str[i + 1] == '\0')
				w++;
		}
		i++;
	}
	return (w);
}

char **ft_split(char *str)
{
	int w;
	int i;
	int l;
	int j;
	char *tmp;
	char **new;

	w  = count_w(str);
	i = 0;
	j = 0;
	if (!(new = (char **)malloc(sizeof(char *) * (w + 1))))
		return (NULL);
	tmp = str;
	while (i < w)
	{
		l = 0;
		j = 0;
		while (*tmp == ' ' || *tmp == '\t' || *tmp == '\n')
			tmp++;
		while(*tmp != ' ' && *tmp != '\t' && *tmp != '\n' && *tmp)
		{
			l++;
			tmp++;
		}
		new[i] = (char *)malloc(sizeof(char) * (l + 1));
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		while(*str != ' ' && *str != '\t' && *str != '\n' && *str)
		{
			new[i][j] = *str;
			j++;
			str++;
		}
		new[i][j] = '\0';
		i++;
	}
	new[w] = NULL;
	return (new);
}

void putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

int main(int argc, char *argv[])
{
	char **str;
	char *tmp;
	int i;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = ft_split(argv[1]);
	while(str[i])
		i++;
	while(str[--i])
	{
		putstr(str[i]);
		if (str[i - 1])
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return 0;
}
