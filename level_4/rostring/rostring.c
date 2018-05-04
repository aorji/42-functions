/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:13:30 by aorji             #+#    #+#             */
/*   Updated: 2018/02/01 21:13:32 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>

void putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

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

int main(int argc, char *argv[])
{
	char **str;
	int i;

	i = 1;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = ft_split(argv[1]);
	while(str[i])
	{
		putstr(str[i]);
		write(1, " ", 1);
		i++;
	}
	putstr(str[0]);
	write(1, "\n", 1);
	return 0;
}