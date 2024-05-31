/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:20:12 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/02 15:04:04 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, t_ins **instructs)
{
	t_stack	*last;
	t_stack	*curr;

	last = my_lstlast(*a);
	curr = *a;
	while (curr->next)
	{
		if (NULL == curr->next->next)
			curr->next = NULL;
		if (curr->next)
			curr = curr->next;
	}
	last->next = *a;
	*a = last;
	if (instructs)
		push_in_instructs(instructs, "rra\n");
}

void	rrb(t_stack **b, t_ins **instructs)
{
	t_stack	*last;
	t_stack	*curr;

	last = my_lstlast(*b);
	curr = *b;
	while (curr->next)
	{
		if (NULL == curr->next->next)
			curr->next = NULL;
		if (curr->next)
			curr = curr->next;
	}
	last->next = *b;
	*b = last;
	if (instructs)
		push_in_instructs(instructs, "rrb\n");
}

void	rrr(t_stack **a, t_stack **b, t_ins **instructs)
{
	rra(a, NULL);
	rrb(b, NULL);
	push_in_instructs(instructs, "rrr\n");
}
