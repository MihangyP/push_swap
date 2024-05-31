/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_big_than.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:09:40 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/04 02:51:16 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_big_than_a(t_stack **b, int n)
{
	t_stack	*curr;
	int		big_than_a;
	int		found;
	int		i;
	int		j;

	curr = *b;
	found = 0;
	i = 0;
	while (curr && ++i)
	{
		if (found && curr->value < n && curr->value > big_than_a)
		{
			big_than_a = curr->value;
			j = i;
		}
		if (curr->value < n && !found)
		{
			found = 1;
			big_than_a = curr->value;
			j = i;
		}
		curr = curr->next;
	}
	return (j);
}

int	search_big_than_b(t_stack **a, int n)
{
	t_stack	*curr;
	int		big_than_b;
	int		found;
	int		i;
	int		j;

	curr = *a;
	found = 0;
	i = 0;
	while (curr && ++i)
	{
		if (found && curr->value > n && curr->value < big_than_b)
		{
			big_than_b = curr->value;
			j = i;
		}
		if (curr->value > n && !found)
		{
			found = 1;
			big_than_b = curr->value;
			j = i;
		}
		curr = curr->next;
	}
	return (j);
}
