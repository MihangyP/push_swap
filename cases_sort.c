/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:16:18 by pmihangy          #+#    #+#             */
/*   Updated: 2024/04/26 13:13:56 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_lb_2(t_stack **a, t_stack **b, int i_a, t_ins **ins)
{
	int	i;
	int	l_a;
	int	i_b;

	l_a = stack_len(*a);
	i_b = find_greatest_index(b);
	i = -1;
	while (++i < i_a - 1 && i_b == 1 && i_a < (l_a / 2))
		ra(a, ins);
	i = -1;
	if (i_a != 1 && i_b == 2 && i_a <= (l_a / 2))
		rr(a, b, ins);
	else if (i_b == 2 && i_a <= (l_a / 2))
		rb(b, ins);
	while (++i < i_a - 2 && i_b == 2 && i_a <= (l_a / 2))
		ra(a, ins);
	i = -1;
	while (++i < l_a - i_a + 1 && i_b == 1 && i_a > (l_a / 2))
		rra(a, ins);
	case_lb_2_next(a, b, i_a, ins);
}

void	case_one(t_stack **a, t_stack **b, t_ins **ins, int i_b)
{
	int	i;
	int	j;
	int	i_a;

	i_a = find_cheapest(a, b, stack_len(*a));
	i = -1;
	if (i_b - 1 > i_a - 1)
		j = i_a - 1;
	else if (i_b - 1 < i_a - 1)
		j = i_b - 1;
	else
		j = i_b - 1;
	case_one_next(a, b, ins, j);
	if (i_b - 1 > i_a - 1)
	{
		while (++i < (i_b - 1) - (i_a - 1))
			rb(b, ins);
	}
	if (i_b - 1 < i_a - 1)
	{
		while (++i < (i_a - 1) - (i_b - 1))
			ra(a, ins);
	}
	pb(b, a, ins);
}

void	case_two(t_stack **a, t_stack **b, t_ins **ins, int i_b)
{
	int	i;
	int	l_a;
	int	i_a;

	l_a = stack_len(*a);
	i_a = find_cheapest(a, b, l_a);
	i = -1;
	while (++i < i_b - 1)
		rb(b, ins);
	i = -1;
	while (++i < l_a - i_a + 1)
		rra(a, ins);
	pb(b, a, ins);
}

void	case_three(t_stack **a, t_stack **b, t_ins **ins, int i_b)
{
	int	i;
	int	j;
	int	l_a;
	int	l_b;
	int	i_a;

	l_a = stack_len(*a);
	l_b = stack_len(*b);
	i_a = find_cheapest(a, b, l_a);
	i = -1;
	j = get_j(i_a, i_b, l_a, l_b);
	while (++i < j)
		rrr(a, b, ins);
	i = -1;
	if (l_b - i_b + 1 < l_a - i_a + 1)
	{
		while (++i < (l_a - i_a + 1) - (l_b - i_b + 1))
			rra(a, ins);
	}
	if (l_b - i_b + 1 > l_a - i_a + 1)
	{
		while (++i < (l_b - i_b + 1) - (l_a - i_a + 1))
			rrb(b, ins);
	}
	pb(b, a, ins);
}

void	case_four(t_stack **a, t_stack **b, t_ins **ins, int i_b)
{
	int	i;
	int	i_a;
	int	l_b;

	i_a = find_cheapest(a, b, stack_len(*a));
	l_b = stack_len(*b);
	i = -1;
	while (++i < l_b - i_b + 1)
		rrb(b, ins);
	i = -1;
	while (++i < i_a - 1)
		ra(a, ins);
	pb(b, a, ins);
}
