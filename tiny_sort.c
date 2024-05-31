/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:45:45 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/23 15:08:33 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tiny_sort(t_stack **a, t_stack **b, t_ins **ins)
{
	int	l_a;

	l_a = stack_len(*a);
	if (2 == l_a && !is_sorted(*a))
		return (very_quick_sort(*a, ins));
	if (3 == l_a && !is_sorted(*a))
		quick_sort(a, ins);
	return (1);
}

void	sort_few(t_stack **a, t_stack **b, t_ins **ins, int len_a)
{
	if (len_a == 4)
	{
		pb(b, a, ins);
		final_sort(a, b, ins);
	}
	if (len_a == 5)
		sort_five(a, b, ins);
}
