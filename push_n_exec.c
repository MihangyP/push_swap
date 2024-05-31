/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:26:39 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/09 13:17:50 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ins(t_stack **a, t_stack **b, t_ins **ins, int i_a)
{
	int		l_a;
	int		l_b;
	int		i_b;
	t_stack	*a_c;

	l_a = stack_len(*a);
	l_b = stack_len(*b);
	i_b = find_greatest_index(b);
	a_c = find_a(a, find_cheapest(a, b, l_a));
	if (!is_new_min(*b, a_c->value) && !is_new_max(*b, a_c->value))
		i_b = search_big_than_a(b, a_c->value);
	if (2 == l_b)
		case_lb_2(a, b, i_a, ins);
	if (l_b != 2 && i_b <= (l_b / 2) && i_a <= (l_a / 2))
		case_one(a, b, ins, i_b);
	if (l_b != 2 && i_b <= (l_b / 2) && i_a > (l_a / 2))
		case_two(a, b, ins, i_b);
	if (l_b != 2 && i_b > (l_b / 2) && i_a > (l_a / 2))
		case_three(a, b, ins, i_b);
	if (l_b != 2 && i_b > (l_b / 2) && i_a <= (l_a / 2))
		case_four(a, b, ins, i_b);
}

void	push_cost_a(t_stack *a, t_stack **b, int i_b, int i_a)
{
	int	l_a;
	int	l_b;

	l_a = stack_len(a) + i_a - 1;
	l_b = stack_len(*b);
	if (!is_new_min(*b, a->value) && !is_new_max(*b, a->value))
		i_b = search_big_than_a(b, a->value);
	if (2 == l_b)
		cost_lb_2(a, i_b, i_a, l_a);
	if (l_b != 2 && i_b <= (l_b / 2) && i_a <= (l_a / 2))
		cost_one(a, i_b, i_a, l_a);
	if (l_b != 2 && i_b <= (l_b / 2) && i_a > (l_a / 2))
		cost_two(a, i_b, i_a, l_a);
	if (l_b != 2 && i_b > (l_b / 2) && i_a > (l_a / 2))
		cost_three(a, i_b, i_a, l_b);
	if (l_b != 2 && i_b > (l_b / 2) && i_a <= (l_a / 2))
		cost_four(a, i_b, i_a, l_b);
}
