/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 21:03:53 by aorji             #+#    #+#             */
/*   Updated: 2018/01/28 21:03:54 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *s)
{
	int len;

	len = 0;
	while(s[len])
		len++;
	return (len);
}
int main(int argc, char** argv)
{
	int l;

	if (argc != 2 || !(l = ft_strlen(argv[1])))
	{
		write(1, "\n", 1);
		return (0);
	}
	l--;
	while(argv[1][l] == ' ' || argv[1][l] == '\t')
		l--;
	while (argv[1][l] != ' ' && argv[1][l] != '\t' && argv[1][l])
		l--;
	l++;
	while (argv[1][l] != ' ' && argv[1][l] != '\t' && argv[1][l])
	{
		write(1, &argv[1][l], 1);
		l++;
	}
	write(1, "\n", 1);
	return (0);
}

