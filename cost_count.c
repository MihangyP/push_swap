/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:12:38 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/09 13:16:29 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_lb_2(t_stack *a, int i_b, int i_a, int l_a)
{
	int	i;

	i = -1;
	while (++i < i_a - 1 && i_b == 1 && i_a < (l_a / 2))
		a->cost = a->cost + 1;
	i = -1;
	if (i_a != 1 && i_b == 2 && i_a <= (l_a / 2))
		a->cost = a->cost + 1;
	else if (i_b == 2 && i_a <= (l_a / 2))
		a->cost = a->cost + 1;
	while (++i < i_a - 2 && i_b == 2 && i_a <= (l_a / 2))
		a->cost = a->cost + 1;
	i = -1;
	while (++i < l_a - i_a + 1 && i_b == 1 && i_a > (l_a / 2))
		a->cost = a->cost + 1;
	if (i_b == 2 && i_a > (l_a / 2))
	{
		i = -1;
		a->cost = a->cost + 1;
		while (++i < l_a - i_a + 1)
			a->cost = a->cost + 1;
	}
	a->cost = a->cost + 1;
}

void	cost_one(t_stack *a, int i_b, int i_a, int l_a)
{
	int	i;
	int	j;

	i = -1;
	if (i_b - 1 > i_a - 1)
		j = i_a - 1;
	else if (i_b - 1 < i_a - 1)
		j = i_b - 1;
	else
		j = i_b - 1;
	while (++i < j)
		a->cost = a->cost + 1;
	i = -1;
	while (++i < (i_b - 1) - (i_a - 1) && i_b - 1 > i_a - 1)
		a->cost = a->cost + 1;
	while (++i < (i_a - 1) - (i_b - 1) && i_b - 1 < i_a - 1)
		a->cost = a->cost + 1;
	a->cost = a->cost + 1;
}

void	cost_two(t_stack *a, int i_b, int i_a, int l_a)
{
	int	i;

	i = -1;
	while (++i < i_b - 1)
		a->cost = a->cost + 1;
	i = -1;
	while (++i < l_a - i_a + 1)
		a->cost = a->cost + 1;
	a->cost = a->cost + 1;
}

void	cost_three(t_stack *a, int i_b, int i_a, int l_b)
{
	int	i;
	int	j;
	int	l_a;

	i = -1;
	l_a = stack_len(a) + i_a - 1;
	if (l_b - i_b + 1 < l_a - i_a + 1)
		j = l_b - i_b + 1;
	else if (l_b - i_b + 1 > l_a - i_a + 1)
		j = l_a - i_a + 1;
	else
		j = l_b - i_b + 1;
	while (++i < j)
		a->cost = a->cost + 1;
	i = -1;
	cost_three_next(&a, i_b, i_a, l_b);
}

void	cost_four(t_stack *a, int i_b, int i_a, int l_b)
{
	int	i;

	i = -1;
	while (++i < l_b - i_b + 1)
		a->cost = a->cost + 1;
	i = -1;
	while (++i < i_a - 1)
		a->cost = a->cost + 1;
	a->cost = a->cost + 1;
}
