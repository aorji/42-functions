/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 21:51:03 by aorji             #+#    #+#             */
/*   Updated: 2018/01/28 21:51:05 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i;

	i = 128;
	while (i)
	{
		if (octet / i)
		{
			write(1, "1", 1);
			octet -= i;
		}
		else
			write(1, "0", 1);
		i /= 2;
	}
}

int main()
{
	print_bits(193);
	return 0;
}