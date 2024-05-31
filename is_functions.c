/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:09:22 by pmihangy          #+#    #+#             */
/*   Updated: 2024/04/25 17:39:27 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	is_sorted(t_stack *a)
{
	int	i;

	i = a->value;
	while (a)
	{
		if (i > a->value)
			return (false);
		i = a->value;
		a = a->next;
	}
	return (true);
}

unsigned int	is_greatest(t_stack *a, int b)
{
	int		greatest;
	t_stack	*curr;

	curr = a;
	greatest = curr->value;
	while (curr)
	{
		if (curr->value > greatest)
			greatest = curr->value;
		curr = curr->next;
	}
	return (greatest == b);
}
