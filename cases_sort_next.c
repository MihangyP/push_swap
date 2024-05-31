/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_sort_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:09:20 by pmihangy          #+#    #+#             */
/*   Updated: 2024/04/26 13:12:08 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_lb_2_next(t_stack **a, t_stack **b, int i_a, t_ins **ins)
{
	int	i;
	int	l_a;
	int	i_b;

	l_a = stack_len(*a);
	i_b = find_greatest_index(b);
	if (i_b == 2 && i_a > (l_a / 2))
	{
		i = -1;
		rb(b, ins);
		while (++i < l_a - i_a + 1)
			rra(a, ins);
	}
	pb(b, a, ins);
}

void	case_one_next(t_stack **a, t_stack **b, t_ins **ins, int j)
{
	int	i;

	i = -1;
	while (++i < j)
		rr(a, b, ins);
}

int	get_j(int i_a, int i_b, int l_a, int l_b)
{
	int	j;

	if (l_b - i_b + 1 < l_a - i_a + 1)
		j = l_b - i_b + 1;
	else if (l_b - i_b + 1 > l_a - i_a + 1)
		j = l_a - i_a + 1;
	else
		j = l_b - i_b + 1;
	return (j);
}
