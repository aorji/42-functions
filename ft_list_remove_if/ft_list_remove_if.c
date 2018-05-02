/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 10:15:03 by exam              #+#    #+#             */
/*   Updated: 2018/03/27 10:37:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *new;
	t_list *tmp;

	while (*begin_list && (*cmp)(data_ref, (*begin_list)->data) == 0)
	{
		tmp = (*begin_list);
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	new = *begin_list;
	while(new && new->next)
	{
		if ((*cmp)(new->next->data, data_ref) == 0)
		{
			tmp = new->next;
			new->next = new->next->next;
			free(tmp);
		}
		else
			new = new->next;
	}
}

