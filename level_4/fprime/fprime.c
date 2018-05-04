/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:57:50 by aorji             #+#    #+#             */
/*   Updated: 2018/01/31 16:57:54 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int a;
	int b;

	a = atoi(argv[1]);
	b = 2;
	if (argc != 2 || a < 0)
		return (printf("\n"));
	if (a == 1)
		return (printf("1\n"));
	while(1)
	{
		if (a%b == 0)
		{
			printf("%d", b);
			a /=b;
			if (a != 1)
				printf("*");
			else
			{
				printf("\n");
				break;
			}
			b = 1;
		}
		b++;
	}
}
