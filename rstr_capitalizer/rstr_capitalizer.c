/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:25:13 by exam              #+#    #+#             */
/*   Updated: 2018/01/09 13:56:21 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	plus(char **b, int i, int j)
{
	if (b[i][j] <= 90 && b[i][j] >= 65)
		b[i][j] = b[i][j] + 32;
	write(1, &b[i][j], 1);
}

void	minus(char **b, int i, int j)
{
	if (b[i][j] >= 97 && b[i][j] <= 122)
		b[i][j] = b[i][j] - 32;
	write(1, &b[i][j], 1);
}

int		main(int a, char **b)
{
	int	i;
	int	j;

	i = 1;
	if (a == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (b[i])
	{
		j = 0;
		while (b[i][j])
		{
			if (b[i][j] == ' ' || b[i][j] == '\t')
				write(1, &b[i][j], 1);
			if (b[i][j + 1] != ' ' && b[i][j] != '\t' && b[i][j + 1] != '\0')
				plus(b, i, j);
			else
				minus(b, i, j);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
