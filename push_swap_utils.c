/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:06:33 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/23 15:00:29 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_instructs_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

int	count_el_in_arr(char **arr)
{
	int	i;

	i = 0;
	if (NULL == arr)
		return (0);
	while (arr[i])
		++i;
	return (i);
}

int	find_cheapest_n(t_stack **stack)
{
	t_stack	*curr;
	int		cost;
	int		i;
	int		j;

	curr = *stack;
	cost = curr->cost;
	i = 1;
	j = 1;
	while (curr)
	{
		if (curr->cost < cost)
		{
			j = i;
			cost = curr->cost;
		}
		++i;
		curr = curr->next;
	}
	return (j);
}

t_stack	*find_a(t_stack **a, int n)
{
	t_stack	*curr;
	int		i;

	curr = *a;
	i = 1;
	while (curr)
	{
		if (i == n)
			break ;
		++i;
		curr = curr->next;
	}
	return (curr);
}

void	cost_three_next(t_stack **a, int i_b, int i_a, int l_b)
{
	int	l_a;
	int	i;

	l_a = stack_len(*a) + i_a - 1;
	i = 0;
	if (l_b - i_b + 1 < l_a - i_a + 1)
	{
		while (++i < (l_a - i_a + 1) - (l_b - i_b + 1))
			(*a)->cost = (*a)->cost + 1;
	}
	if (l_b - i_b + 1 > l_a - i_a + 1)
	{
		while (++i < (l_b - i_b + 1) - (l_a - i_a + 1))
			(*a)->cost = (*a)->cost + 1;
	}
	(*a)->cost = (*a)->cost + 1;
}
