/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:56:04 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/12 15:59:10 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stack_next(t_stack **a, char **av, int i)
{
	t_stack	*new;

	new = new_element(ft_atoi(av[i]));
	if (NULL)
	{
		free_stack(a, i);
		return (0);
	}
	my_lstadd_back(a, new);
	return (1);
}

int	create_stack_one_string_next(t_stack **a, char **arr, int i)
{
	t_stack	*new;

	new = new_element(ft_atoi(arr[i]));
	if (NULL == new)
	{
		free_stack(a, i);
		return (0);
	}
	my_lstadd_back(a, new);
	return (1);
}
