/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 22:03:13 by aorji             #+#    #+#             */
/*   Updated: 2018/01/28 22:03:14 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char res;
	int c;

	c = 8;
	res = 0;

	while(c)
	{
		res = res * 2 + (octet % 2);
		octet /= 2;
		c--;
	}
	return (res);
}
