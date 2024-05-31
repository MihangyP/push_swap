/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lst_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:27:22 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/24 15:24:41 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*my_lstlast(t_stack *lst)
{
	t_stack	*curr;

	curr = lst;
	if (!curr)
		return (NULL);
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	my_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (NULL != lst)
	{
		if (NULL == *lst)
			*lst = new;
		else
		{
			last = my_lstlast(*lst);
			last->next = new;
		}
	}
}
