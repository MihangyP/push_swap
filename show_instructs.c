/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_instructs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:46:10 by pmihangy          #+#    #+#             */
/*   Updated: 2024/04/25 17:41:37 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_instructs(t_ins **ins)
{
	t_ins	*curr;

	curr = *ins;
	while (curr)
	{
		ft_putstr_fd(curr->content, 1);
		curr = curr->next;
	}
}
