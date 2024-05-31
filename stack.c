/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:53:57 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/23 16:16:52 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_element(int value)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (NULL == new_stack)
		return (NULL);
	new_stack->value = value;
	new_stack->init = 1;
	new_stack->cost = 0;
	new_stack->next = NULL;
	return (new_stack);
}

unsigned int	stack_len(t_stack *stack)
{
	t_stack			*curr;
	unsigned int	counter;

	curr = stack;
	counter = 0;
	while (curr)
	{
		++counter;
		curr = curr->next;
	}
	return (counter);
}

char	**join_arr(char **numbers, char **arr)
{
	char	**n_arr;
	int		size;
	int		i;

	size = count_el_in_arr(numbers) + count_el_in_arr(arr);
	n_arr = malloc((size + 1) * sizeof(char *));
	if (NULL == n_arr)
		return (free_arr(arr), NULL);
	i = 0;
	while (numbers && numbers[i])
	{
		n_arr[i] = ft_strdup(numbers[i]);
		if (NULL == n_arr[i])
			return (free_arr(arr), free_arr(n_arr), NULL);
		++i;
	}
	if (!join_arr_next(n_arr, arr, i))
		return (free_arr(arr), free_arr(n_arr), NULL);
	if (numbers)
		free_arr(numbers);
	free_arr(arr);
	return (n_arr);
}

int	create_stack(t_stack **a, char **av, int ac)
{
	int		i;
	t_stack	*new;
	char	**numbers;

	i = 0;
	numbers = catch_data(av, ac);
	if (NULL == numbers)
		return (0);
	while (numbers[i])
	{
		if (0 == (*a)->init)
		{
			(*a)->init = 1;
			(*a)->cost = 0;
			(*a)->value = ft_atoi(numbers[i]);
			(*a)->next = NULL;
		}
		else
		{
			if (!create_stack_next(a, numbers, i))
				return (0);
		}
		++i;
	}
	return (free_arr(numbers), 1);
}
