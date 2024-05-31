/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 03:38:47 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/23 16:15:26 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_of_five(t_stack **a)
{
	t_stack	*curr;
	int		max;
	int		i;
	int		j;

	curr = *a;
	max = curr->value;
	i = 1;
	j = i;
	while (curr)
	{
		if (curr->value > max)
		{
			max = curr->value;
			j = i;
		}
		curr = curr->next;
		++i;
	}
	return (j);
}

int	find_five(t_stack **a)
{
	t_stack	*curr;
	int		max;

	curr = *a;
	max = curr->value;
	while (curr)
	{
		if (curr->value > max)
			max = curr->value;
		curr = curr->next;
	}
	return (max);
}

int	find_four(t_stack **a)
{
	return (search_big_than_a(a, find_five(a)));
}

void	sort_five(t_stack **a, t_stack **b, t_ins **ins)
{
	int	to_push;
	int	i;

	to_push = find_four(a);
	i = -1;
	while (to_push <= 3 && ++i < to_push - 1)
		ra(a, ins);
	i = -1;
	while (to_push > 3 && ++i < 5 - to_push + 1)
		rra(a, ins);
	pb(b, a, ins);
	to_push = find_index_of_five(a);
	i = -1;
	while (to_push <= 3 && ++i < to_push - 1)
		ra(a, ins);
	i = -1;
	while (to_push > 3 && ++i < 4 - to_push + 1)
		rra(a, ins);
	pb(b, a, ins);
	quick_sort(a, ins);
	pa(a, b, ins);
	pa(a, b, ins);
	ra(a, ins);
	ra(a, ins);
}
