/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:03:29 by exam              #+#    #+#             */
/*   Updated: 2018/03/13 10:23:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_lst_len(t_list *l)
{
	int i;

	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *new;
	int len;
	int i;
	int j;
	int n;

	len = ft_lst_len(lst);
	i = 0;
	while (i < len)
	{
		j = 0;
		new = lst;
		while (j < len - 1)
		{
			if ((*cmp)(new->data, new->next->data) == 0)
			{
				n = new->data;
				new->data = new->next->data;
				new->next->data = n;
			}
			new = new->next;
			j++;
		}
		i++;
	}
	return (lst);
}

