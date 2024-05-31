/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:42:23 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/17 08:21:01 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* HACK: Algorithm
 * - We slowly push everything from the STACK_A to STACK_B but in 
 *   descending order.
 *   Because after we push them back to STACK_A, they will be 
 *   automatically sorted.
 * - Stacks are kind of circular linked list. It means, the last
 *   element of the stack 
 *   is actually not the last element. It is actually an element before 
 *   the first element.
 * - If the number you push from STACK_A to STACK_B is going to be the new
 *   biggest or the smallest number, you should place it just above the old
 *   biggest number in the stack STACK_B.
 * - 1. Push 2 number to STACK_A 
 *   In order to determine a number's correct position in
 *   STACK_B, we need a maximum number in STACK_B.
 *   So, we start with pushing two numbers from the top of 
 *   STACK_A to the STACK_B without checking anything.
 * - 2. Find the cheapest number and push it to STACK_B
 * - 3. Last three elemets: use quick_sort
 * - 4. Time to push back to STACK_A
 * - 5. Final arrangement.
 *      We should bring the minimum number of the stack to the top 
 *      of the stack
 *
*/

int	find_cheapest(t_stack **a, t_stack **b, unsigned int l_a)
{
	t_stack			*curr_a;
	int				cheapest_n;
	unsigned int	l_b;
	int				i;

	l_b = stack_len(*b);
	curr_a = *a;
	i = 1;
	while (curr_a)
	{
		push_cost_a(curr_a, b, find_greatest_index(b), i);
		curr_a = curr_a->next;
		++i;
	}
	cheapest_n = find_cheapest_n(a);
	return (cheapest_n);
}

void	clean_instructs(t_stack **a, t_stack **b)
{
	t_stack	*curr;

	curr = *a;
	while (curr)
	{
		curr->cost = 0;
		curr = curr->next;
	}
	curr = *b;
	while (curr)
	{
		curr->cost = 0;
		curr = curr->next;
	}
}

void	exec_ins_ab(t_stack **a, t_stack **b, int i_a, t_ins **ins)
{
	int	i;
	int	l_a;

	l_a = stack_len(*a);
	i = -1;
	while (++i < i_a - 1 && i_a <= (l_a / 2))
		ra(a, ins);
	i = -1;
	while (++i < l_a - i_a + 1 && i_a > (l_a / 2))
		rra(a, ins);
	pa(a, b, ins);
}

void	final_sort(t_stack **a, t_stack **b, t_ins **instructs)
{
	t_stack			*curr;
	int				big_than_b;

	if (!is_sorted(*a))
		quick_sort(a, instructs);
	curr = *b;
	while (curr)
	{
		if (is_new_max(*a, curr->value))
			big_than_b = find_max(a);
		else
			big_than_b = search_big_than_b(a, curr->value);
		exec_ins_ab(a, b, big_than_b, instructs);
		curr = *b;
	}
	if (!is_sorted(*a))
		donto_sort(a, stack_len(*a), instructs);
}

void	push_swap(t_stack **a, t_stack **b, t_ins **instructs)
{
	int				cheapest_n;
	unsigned int	len_a;
	t_stack			*curr;

	len_a = stack_len(*a);
	if (len_a == 4 || len_a == 5)
	{
		sort_few(a, b, instructs, len_a);
		return ;
	}
	pb(b, a, instructs);
	pb(b, a, instructs);
	len_a = stack_len(*a);
	while (len_a > 3)
	{
		cheapest_n = find_cheapest(a, b, len_a);
		exec_ins(a, b, instructs, cheapest_n);
		clean_instructs(a, b);
		--len_a;
	}
	final_sort(a, b, instructs);
}
