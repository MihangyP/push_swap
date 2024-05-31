/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:27:33 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/23 16:17:46 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	join_arr_next(char **n_arr, char **arr, int i)
{
	int	j;

	j = 0;
	while (arr && arr[j])
	{
		n_arr[i] = ft_strdup(arr[j]);
		if (NULL == n_arr[i])
			return (0);
		++j;
		++i;
	}
	n_arr[i] = NULL;
	return (1);
}

char	**catch_data(char **av, int ac)
{
	int		i;
	char	**arr;
	char	**numbers;

	i = 0;
	numbers = NULL;
	while (++i < ac)
	{
		arr = ft_split(av[i], ' ');
		if (NULL == arr)
		{
			if (numbers)
				free_arr(numbers);
			return (NULL);
		}
		numbers = join_arr(numbers, arr);
	}
	return (numbers);
}
