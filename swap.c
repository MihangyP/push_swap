/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:28:41 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/09 10:16:11 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *a, t_ins **instructs)
{
	int	tmp;

	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	if (instructs)
	{
		if (!push_in_instructs(instructs, "sa\n"))
			return (0);
	}
	return (1);
}

void	sb(t_stack *b, t_ins **instructs)
{
	int	tmp;

	tmp = b->value;
	b->value = b->next->value;
	b->next->value = tmp;
	if (instructs)
		push_in_instructs(instructs, "sb\n");
}

void	ss(t_stack *a, t_stack *b, t_ins **instructs)
{
	sa(a, NULL);
	sb(b, NULL);
	push_in_instructs(instructs, "ss\n");
}
