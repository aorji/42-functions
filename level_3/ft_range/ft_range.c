/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:50:36 by aorji             #+#    #+#             */
/*   Updated: 2018/01/29 19:50:38 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int *str;
	int i;

	if (end >= start)
	{
		i = end - start + 1;
		str = (int *)malloc(sizeof(int) * i);
		while (i)
		{
			str[i  - 1] = end;
			end--;
			i--;
		}
	}
	else if (end < start)
	{
		i = start - end + 1;
		str = (int *)malloc(sizeof(int) * i);
		while (i)
		{
			str[i - 1] = end;
			end++;
			i--;
		}
	}
	return (str);
}

int main()
{
	int i = 0;
	int *a;
	a = ft_range(0, 0);
	while (i < 1)
	{
		printf("%d", a[i]);
		i++;
	}
	printf("%s", "\n");
	return 0;
}