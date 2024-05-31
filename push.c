/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:30:06 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/09 12:46:21 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, t_ins **instructs)
{
	int		tmp_v;
	t_stack	*el;

	tmp_v = (*b)->value;
	el = new_element(tmp_v);
	el->next = *a;
	*a = el;
	del(b);
	push_in_instructs(instructs, "pa\n");
}

void	pb(t_stack **b, t_stack **a, t_ins **instructs)
{
	int		tmp_v;
	t_stack	*el;

	tmp_v = (*a)->value;
	el = new_element(tmp_v);
	if (0 == (*b)->init)
	{
		free(*b);
		*b = el;
		(*b)->init = 1;
		del(a);
		push_in_instructs(instructs, "pb\n");
		return ;
	}
	el->next = *b;
	*b = el;
	del(a);
	push_in_instructs(instructs, "pb\n");
}
