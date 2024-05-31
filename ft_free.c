/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:19:02 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/23 14:40:45 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr[i]);
	free(arr);
}

void	free_stack(t_stack **stack, int i)
{
	t_stack	*curr;
	t_stack	*tmp;
	int		j;

	curr = *stack;
	j = 0;
	while (i > j)
	{
		tmp = curr;
		++j;
		curr = curr->next;
		tmp = NULL;
		free(tmp);
	}
	stack = NULL;
	free(stack);
}

void	free_instructs(t_ins **ins)
{
	t_ins	*curr;
	t_ins	*tmp;

	curr = *ins;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp->content);
		free(tmp);
	}
}

void	free_ab(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
