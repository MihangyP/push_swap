/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:01:41 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/04 01:57:35 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	is_new_min(t_stack *stack, int n)
{
	t_stack	*curr;

	curr = stack;
	while (curr)
	{
		if (curr->value < n)
			return (false);
		curr = curr->next;
	}
	return (true);
}

unsigned int	is_new_max(t_stack *stack, int n)
{
	t_stack	*curr;

	curr = stack;
	while (curr)
	{
		if (curr->value > n)
			return (false);
		curr = curr->next;
	}
	return (true);
}

int	find_min_i(t_stack *a)
{
	t_stack	*curr;
	int		min;

	min = a->value;
	curr = a;
	while (curr)
	{
		if (curr->value < min)
			min = curr->value;
		curr = curr->next;
	}
	return (min);
}

int	find_max(t_stack **stack)
{
	t_stack		*curr;
	int			max;
	int			i;

	curr = *stack;
	max = curr->value;
	while (curr)
	{
		if (curr->value > max)
			max = curr->value;
		curr = curr->next;
	}
	i = 1;
	curr = *stack;
	while (curr)
	{
		if (curr->value == max)
			break ;
		++i;
		curr = curr->next;
	}
	return (i + 1);
}

unsigned int	find_greatest_index(t_stack **stack)
{
	unsigned int	i;
	unsigned int	j;
	int				greatest;
	t_stack			*curr;

	curr = *stack;
	greatest = curr->value;
	i = 1;
	j = 1;
	while (curr)
	{
		if (curr->value > greatest)
		{
			greatest = curr->value;
			j = i;
		}
		++i;
		curr = curr->next;
	}
	return (j);
}
