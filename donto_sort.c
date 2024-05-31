/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   donto_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:00:16 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/01 16:37:41 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	very_donto_sort(t_stack **a, int i, int l_a, t_ins **ins)
{
	int	j;

	j = -1;
	while (++j < i - 1 && i <= (l_a / 2))
		ra(a, ins);
	j = -1;
	while (++j < l_a - i + 1 && i > (l_a / 2))
		rra(a, ins);
}

void	donto_sort(t_stack **a, int l_a, t_ins **instructs)
{
	int		min;
	int		i;
	t_stack	*curr;

	min = find_min_i(*a);
	curr = *a;
	i = 1;
	while (curr)
	{
		if (curr->value == min)
			very_donto_sort(a, i, l_a, instructs);
		++i;
		curr = curr->next;
	}
}
