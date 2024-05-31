/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:05:53 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/01 15:51:06 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	very_quick_sort(t_stack *a, t_ins **instructs)
{
	return (sa(a, instructs));
}

void	quick_sort(t_stack **a, t_ins **instructs)
{
	if (is_greatest(*a, (*a)->next->value))
		rra(a, instructs);
	else if (is_greatest(*a, (*a)->value))
		ra(a, instructs);
	else
		sa(*a, instructs);
	if (!is_sorted(*a))
		sa(*a, instructs);
}
