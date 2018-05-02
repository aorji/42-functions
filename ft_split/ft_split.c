/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:03:17 by exam              #+#    #+#             */
/*   Updated: 2018/03/06 10:36:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_w(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n' && *str &&
				(*(str + 1) == ' ' || *(str + 1) == '\t' || *(str + 1) == '\0' || *(str + 1) == '\n'))
		{
			i++;
		}
		str++;
	}
	return (i);
}

int ft_l(char *str)
{
	int i;
	i = 0;
	while (*str != ' ' && *str != '\t' && *str != '\n' && *str)
	{
		str++;
		i++;
	}
	return (i);
}

char *ft_sw(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	return (str);
}

char    **ft_split(char *str)
{
	char **new;
	int w;
	int l;
	int i;
	int j;

	if (!str)
		return (NULL);
	w = ft_w(str);
	if (!(new = (char **)malloc(sizeof(char *) * (w + 1))))
		return (NULL);
	i = 0;
	while (i < w)
	{
		str = ft_sw(str);
		l = ft_l(str);
		new[i] = (char *)malloc(sizeof(char) * (l + 1));
		j = 0;
		while (j < l)
		{
			new[i][j] = *str;
			j++;
			str++;
		}
		new[i][j] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}
