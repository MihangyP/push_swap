/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:25:06 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/24 15:21:29 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_an_error_next(char **numbers, int i)
{
	if (!is_int(numbers[i]))
		return (0);
	if (!is_number(numbers[i]))
		return (0);
	return (1);
}

unsigned int	has_an_error(int ac, char **av)
{
	int		i;
	char	**arr;
	char	**numbers;

	i = 0;
	numbers = NULL;
	while (++i < ac)
	{
		if (av[i][0] == '\0')
			return (true);
		arr = ft_split(av[i], ' ');
		if (NULL == arr || NULL == arr[0])
			return (true);
		numbers = join_arr(numbers, arr);
	}
	i = -1;
	if (has_double(numbers, count_el_in_arr(numbers), 0))
		return (free_arr(numbers), true);
	while (++i < count_el_in_arr(numbers))
	{
		if (!has_an_error_next(numbers, i))
			return (free_arr(numbers), true);
	}
	return (free_arr(numbers), false);
}

void	free_memory(t_stack **a, t_ins **ins)
{
	free_ab(a);
	free_instructs(ins);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_ins	*instructs;

	instructs = NULL;
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (a == NULL || b == NULL)
		return (1);
	if (ac < 2)
		return (free(a), free(b), 1);
	if (has_an_error(ac, av))
		return (free(a), free(b), ft_putstr_fd("Error\n", 2), 1);
	a->init = 0;
	b->init = 0;
	if (!create_stack(&a, av, ac))
		return (1);
	if (!tiny_sort(&a, &b, &instructs))
		return (1);
	if (stack_len(a) > 3 && !is_sorted(a))
		push_swap(&a, &b, &instructs);
	free(b);
	return (show_instructs(&instructs), free_memory(&a, &instructs), false);
}
