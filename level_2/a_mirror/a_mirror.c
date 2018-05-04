/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_mirror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:12:31 by aorji             #+#    #+#             */
/*   Updated: 2018/01/13 17:12:33 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char** argv)
{
	int i;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] >= 65 && argv[1][i] <= 90)
		{
			argv[1][i] = argv[1][i] - 64;
			if (argv[1][i] <= 13)
				argv[1][i] = (13 + (13 - (argv[1][i] - 1)) + 64);
			else
				argv[1][i] = (13 - ((argv[1][i] - 1) - 13) + 64);
		}
		else if (argv[1][i] >= 97 && argv[1][i] <= 122)
		{
			argv[1][i] = argv[1][i] - 96;
			if (argv[1][i] <= 13)
				argv[1][i] = (13 + (13 - (argv[1][i] - 1)) + 96);
			else 
				argv[1][i] = (13 - ((argv[1][i] - 1) - 13) + 96);
		}
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}