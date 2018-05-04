/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:41:12 by aorji             #+#    #+#             */
/*   Updated: 2018/02/01 21:41:14 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void f(void *str)
{
	printf("%s\n", str);
}

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *new;

	new = begin_list;
	while(new)
	{
		(*f)(new->data);
		new = new->next;
	}
}

int main()
{
	t_list *list1 = (t_list *)malloc(sizeof(t_list));
	t_list *list2 = (t_list *)malloc(sizeof(t_list));
	t_list *list3 = NULL;

	list1->data = "1";
	list2->data = "2";
	list1->next = list2;
	list2->next = list3;
	ft_list_foreach(list1, f);

}