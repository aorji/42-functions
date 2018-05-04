/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:39:54 by aorji             #+#    #+#             */
/*   Updated: 2018/01/29 12:39:56 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int    ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return(s1[i] - s2[i]);
	}
	return(s1[i] - s2[i]);
}

int main()
{
	char a[13] = "Hellow";
	char b[13] = "He";
	printf("%d\n", ft_strcmp(a, b));
	printf("%d\n", strcmp(a, b));
}