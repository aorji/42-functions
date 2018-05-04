/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:18:24 by aorji             #+#    #+#             */
/*   Updated: 2018/01/29 18:18:28 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	t_list *list;
	int i;

	list = begin_list;
	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int main()
{
	t_list *lis = (t_list *)malloc(sizeof(t_list));
	t_list *list = (t_list *)malloc(sizeof(t_list));
	t_list *list1 =  NULL;

	lis->next = list;
	list->next = list1;
	
	printf("%d\n", ft_list_size(lis));
	return(0);
}