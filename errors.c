/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:31:16 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/23 16:56:23 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_l(const char *str_n)
{
	int		neg;
	int		i;
	long	num;

	i = 0;
	num = 0;
	neg = 1;
	if ('-' == str_n[i] || '+' == str_n[i])
	{
		if ('-' == str_n[i])
			neg *= -1;
		++i;
	}
	while (str_n[i] >= 48 && str_n[i] <= 57)
	{
		num = num * 10 + (str_n[i] - 48);
		i++;
	}
	return (num * neg);
}

unsigned int	is_int(char *token)
{
	long int	token_n;

	token_n = ft_atoi_l(token);
	return (token_n >= INT_MIN && token_n <= INT_MAX);
}

unsigned int	is_number(char *token)
{
	int	i;

	i = 0;
	if ('+' == token[i] || '-' == token[i])
		++i;
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
			return (false);
		++i;
	}
	if (token[i - 1] == '-' || token[i - 1] == '+')
		return (false);
	return (true);
}

unsigned int	has_double(char **av, int ac, int index)
{
	int	i;
	int	j;

	i = index;
	while (i < ac)
	{
		j = index;
		while (j < ac)
		{
			if (j != i && ft_atoi(av[j]) == ft_atoi(av[i]))
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}
