/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:31:26 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/02 15:03:45 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, t_ins **instructs)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *a;
	*a = (*a)->next;
	last = my_lstlast(*a);
	tmp->next = NULL;
	last->next = tmp;
	if (instructs)
		push_in_instructs(instructs, "ra\n");
}

void	rb(t_stack **b, t_ins **instructs)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *b;
	*b = (*b)->next;
	last = my_lstlast(*b);
	tmp->next = NULL;
	last->next = tmp;
	if (instructs)
		push_in_instructs(instructs, "rb\n");
}

void	rr(t_stack **a, t_stack **b, t_ins **instructs)
{
	ra(a, NULL);
	rb(b, NULL);
	push_in_instructs(instructs, "rr\n");
}
